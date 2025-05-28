;-------------------------------------------------------------------------------
; File: my_asm_logic.asm
; Description: Assembly function to demonstrate accessing C parameters via IX
;              and performing a simple addition.
; For use with Zilog Developer Studio II (ZDS II) for eZ80Acclaim!
;-------------------------------------------------------------------------------

; Define segment for code
; This tells the assembler where the code should be placed.
    segment CODE

; Export the function name for C linkage
; The XDEF directive makes the label (function name) visible to the C compiler
; and linker. The ZDS II assembler automatically prefixes this name with an
; underscore '_' for C linkage [an0333.pdf, 1, 5, 8].
    XDEF _my_add_ints

; Define the assembly function entry point
_my_add_ints:
; This function is called from C as: int my_add_ints(int a, int b);

; C Calling Convention Prologue [an0333.pdf, 4, 6, 7, 14]
; Parameters are passed on the stack. The IX register is used as the frame pointer.
; The C compiler pushes parameters in reverse order (b then a), then calls the function.
; The return address is pushed onto the stack by the CALL instruction.
; A typical prologue in the called function saves the caller's IX and sets IX to SP.
    push    ix          ; Save the caller's IX register onto the stack [an0333.pdf, 14].
    ld      ix, sp      ; Set IX as the frame pointer, pointing to the saved IX [an0333.pdf, 14].

; Access parameters from the stack frame using IX-relative addressing
; According to the ZDS II C calling convention [an0333.pdf, 4, 6, 9]:
; - Return address is 2 bytes (PC is 16-bit) [eZ8 CPU Core Specification um0128.pdf, 51, 61, 100, 112, 207, 249, 276].
; - If the callee pushes IX (as we just did), it uses 2 bytes.
; - Parameters are pushed after the return address.
; Based on AN0333 Example 4B [an0333.pdf, 14], which shows accessing 'int a' at (ix+6)
; and 'int b' at (ix+9), we will use these offsets. This offset accounts for the saved
; IX (2 bytes) and the return address (2 bytes) on the stack below IX, plus the
; parameters themselves, which the documentation states are 3 bytes for 'int' [an0333.pdf, 2].
; The example loads these 3-byte parameters into 16-bit registers (DE and HL) [an0333.pdf, 14],
; suggesting either padding or a specific method of loading parts of the 3-byte value.
; We follow the example's register usage for parameter loading.

    ld      de, (ix+6)  ; Load parameter 'a' (the first 'int' parameter) into DE [an0333.pdf, 14].
                        ; This loads 16 bits starting at address (IX + 6).
    ld      hl, (ix+9)  ; Load parameter 'b' (the second 'int' parameter) into HL [an0333.pdf, 14].
                        ; This loads 16 bits starting at address (IX + 9).

; Perform the desired logic: Add parameter 'a' and parameter 'b'.
; The eZ8 CPU has 16-bit addition instructions [eZ8 CPU Core Specification um0128.pdf, 52, 208].
; Since the example loaded into 16-bit registers DE and HL, we will perform a 16-bit add
; using these registers. Note the potential discrepancy with 'int' being 3 bytes [an0333.pdf, 2],
; which isn't fully resolvable based *solely* on the provided documentation snippets, but the
; register usage in the documented example guides this implementation choice.
    add     hl, de      ; Add the contents of DE to HL. The result is stored in HL.
                        ; HL = HL + DE (effectively HL = b + a, using the loaded 16-bit parts).

; The result of the addition is now in the HL register pair.
; According to the C calling convention for ZDS II, scalar return values for
; 'int' are returned in the HL register pair [an0333.pdf, 6, 9]. This matches our result location.

; C Calling Convention Epilogue [an0333.pdf, 4, 6, 7, 14]
; Restore the stack pointer and the saved IX register.
; The epilogue must restore SP to what it was before the function's prologue,
; and restore the caller's IX.
    ld      sp, ix      ; Restore SP to the value it had before 'ld ix, sp' [an0333.pdf, 7, 14].
                        ; SP is now pointing to the saved IX value.
    pop     ix          ; Restore the caller's original IX value from the stack [an0333.pdf, 7, 14].

; Return from the function
; RET instruction pops the return address (2 bytes) from the stack and jumps to it [eZ8 CPU Core Specification um0128.pdf, 57, 207, 211].
    ret

; End of assembly file
    end