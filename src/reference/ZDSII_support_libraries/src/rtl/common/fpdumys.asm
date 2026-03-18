;--------------------------------------------------------------
; Dumy floating point entry points
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------
;
;	11-20-92	DCF		Initial version
;
	INCLUDE EZ8.INC
        INCLUDE CONFIGS.INC

	SEGMENT CODE

;
;	Code entry points
;
        XDEF __b_fpadd,__b_fpupop1,__b_fpupop2,__b_fppack,__b_fpsub,__b_fpmul,__b_fpdiv
        XDEF __b_fpultof,__b_fpltof,__b_fpftol,__b_fpneg,__b_fpcmp
        XDEF __fpadd,__fpupop1,__fpupop2,__fppack,__fpsub,__fpmul,__fpdiv
        XDEF __fpultof,__fpltof,__fpftol,__fpneg,__fpcmp
        XDEF _asin,_acos,_atan2
        XDEF _atan,_atof,_floor,_ceil,_cosh,_sinh,_exp
        XDEF _fabs,_fmod,_frexp,_ldexp,_log10,_log,_modf,___fprint_send
        XDEF _pow,_sqrt,_tan,_tanh,__u_dtoe,__u_dtof,__u_dtog
        XDEF __u_flt_info,__u_flt_rnd,_strtod
__b_fpadd:
__b_fpupop1:
__b_fpupop2:
__b_fppack:
__b_fpsub:
__b_fpmul:
__b_fpdiv:
__b_fpultof:
__b_fpltof:
__b_fpftol:
__b_fpneg:
__b_fpcmp:
__fpadd:
__fpupop1:
__fpupop2:
__fppack:
__fpsub:
__fpmul:
__fpdiv:
__fpultof:
__fpltof:
__fpftol:
__fpneg:
__fpcmp:
___fprint_send:
_asin:
_acos:
_atan2:
_atan:
_atof:
_floor:
_ceil:
_cosh:
_sinh:
_exp:
_fabs:
_fmod:
_frexp:
_ldexp:
_log10:
_log:
_modf:
_pow:
_sqrt:
_tan:
_tanh:
__u_dtoe:
__u_dtof:
__u_dtog:
__u_flt_info:
__u_flt_rnd:
_strtod:
		RET


;
;	Data
;
        XDEF _0_asin,_0_acos,_0_atan2,_0_atan,_1_atan2,_0_atof
	XDEF _0_atof,_0_ceil,_0_floor,_0_sinh,_0_cosh,_0_exp
        XDEF _0_fabs,_1_fmod,_0_fmod,_1_frexp,_0_frexp
        XDEF _1_frexp,_0_frexp,_0_ldexp,_1_ldexp,_0_log
        XDEF _0_log10,_1_modf,_0_modf,_1_modf,_0_modf
        XDEF _0_pow,_1_pow,_0_sqrt,_0_tan,_0_tanh,_1_strtod,_0_strtod
        XDEF _1_strtod,_0_strtod,_1_strtod,_1__u_dtoe
        XDEF _2__u_dtoe,_0__u_dtoe,_1__u_dtof,_2__u_dtof,_0__u_dtof
        XDEF _1__u_dtog,_2__u_dtog,_0__u_dtog,_1__u_flt_info,_2__u_flt_info
        XDEF _0__u_flt_info,_0__u_flt_rnd,_1__u_flt_rnd


	IF	MODEL == SMALL
		segment NEAR_BSS
	ELSE
		segment FAR_BSS
	ENDIF


_0_asin:
_0_acos:
_0_atan2:
_0_atan:
_1_atan2:
_0_atof:
_0_ceil:
_0_floor:
_0_sinh:
_0_cosh:
_0_exp:
_0_fabs:
_1_fmod:
_0_fmod:
_1_frexp:
_0_frexp:
_0_ldexp:
_1_ldexp:
_0_log:
_0_log10:
_1_modf:
_0_modf:
_0_pow:
_1_pow:
_0_sqrt:
_0_tan:
_0_tanh:
_1_strtod:
_0_strtod:
_1__u_dtoe:
_2__u_dtoe:
_0__u_dtoe:
_1__u_dtof:
_2__u_dtof:
_0__u_dtof:
_1__u_dtog:
_2__u_dtog:
_0__u_dtog:
_1__u_flt_info:
_2__u_flt_info:
_0__u_flt_info:
_0__u_flt_rnd:
_1__u_flt_rnd:


		DS	4

;
;	Create graph nodes to prevent link time errors.
;


	IF	MODEL == SMALL
	.FRAME _n_asin,?_n_asin,RDATA
	.FRAME _n_acos,?_n_acos,RDATA
	.FRAME _n_atan2,?_n_atan2,RDATA
	.FRAME _n_atan,?_n_atan,RDATA
	.FRAME _n_atof,?_n_atof,RDATA
	.FRAME _n_floor,?_n_floor,RDATA
	.FRAME _n_ceil,?_n_ceil,RDATA
	.FRAME _n_cosh,?_n_cosh,RDATA
	.FRAME _n_sinh,?_n_sinh,RDATA
	.FRAME _n_exp,?_n_exp,RDATA
	.FRAME _n_fabs,?_n_fabs,RDATA
	.FRAME _n_fmod,?_n_fmod,RDATA
	.FRAME _n_frexp,?_n_frexp,RDATA
	.FRAME _n_ldexp,?_n_ldexp,RDATA
	.FRAME _n_log10,?_n_log10,RDATA
	.FRAME _n_log,?_n_log,RDATA
	.FRAME _n_modf,?_n_modf,RDATA
	.FRAME _n_pow,?_n_pow,RDATA
	.FRAME _n_sqrt,?_n_sqrt,RDATA
	.FRAME _n_tan,?_n_tan,RDATA
	.FRAME _n_tanh,?_n_tanh,RDATA
	.FRAME _n__u_dtoe,?_n__u_dtoe,RDATA
	.FRAME _n__u_dtof,?_n__u_dtof,RDATA
	.FRAME _n__u_dtog,?_n__u_dtog,RDATA
	.FRAME _n__u_flt_info,?_n__u_flt_info,RDATA
	.FRAME _n__u_flt_rnd,?_n__u_flt_rnd,RDATA
	.FRAME _n_strtod,?_n_strtod,RDATA
	.FRAME _n___fprint_send,?_n___fprint_send,RDATA
	ELSE
	.FRAME _f_asin,?_f_asin,EDATA
	.FRAME _f_acos,?_f_acos,EDATA
	.FRAME _f_atan2,?_f_atan2,EDATA
	.FRAME _f_atan,?_f_atan,EDATA
	.FRAME _f_atof,?_f_atof,EDATA
	.FRAME _f_floor,?_f_floor,EDATA
	.FRAME _f_ceil,?_f_ceil,EDATA
	.FRAME _f_cosh,?_f_cosh,EDATA
	.FRAME _f_sinh,?_f_sinh,EDATA
	.FRAME _f_exp,?_f_exp,EDATA
	.FRAME _f_fabs,?_f_fabs,EDATA
	.FRAME _f_fmod,?_f_fmod,EDATA
	.FRAME _f_frexp,?_f_frexp,EDATA
	.FRAME _f_ldexp,?_f_ldexp,EDATA
	.FRAME _f_log10,?_f_log10,EDATA
	.FRAME _f_log,?_f_log,EDATA
	.FRAME _f_modf,?_f_modf,EDATA
	.FRAME _f_pow,?_f_pow,EDATA
	.FRAME _f_sqrt,?_f_sqrt,EDATA
	.FRAME _f_tan,?_f_tan,EDATA
	.FRAME _f_tanh,?_f_tanh,EDATA
        .FRAME _f__u__dtoe,?_f__u_dtoe,EDATA
        .FRAME _f__u__dtof,?_f__u_dtof,EDATA
        .FRAME _f__u__dtog,?_f__u_dtog,EDATA
	.FRAME _f__u_flt_info,?_f__u_flt_info,EDATA
	.FRAME _f__u_flt_rnd,?_f__u_flt_rnd,EDATA
	.FRAME _f_strtod,?_f_strtod,EDATA
	.FRAME _f___fprint_send,?_f___fprint_send,EDATA
	.FRAME _n_asin,?_n_asin,RDATA
	.FRAME _n_acos,?_n_acos,RDATA
	.FRAME _n_atan2,?_n_atan2,RDATA
	.FRAME _n_atan,?_n_atan,RDATA
	.FRAME _n_atof,?_n_atof,RDATA
	.FRAME _n_floor,?_n_floor,RDATA
	.FRAME _n_ceil,?_n_ceil,RDATA
	.FRAME _n_cosh,?_n_cosh,RDATA
	.FRAME _n_sinh,?_n_sinh,RDATA
	.FRAME _n_exp,?_n_exp,RDATA
	.FRAME _n_fabs,?_n_fabs,RDATA
	.FRAME _n_fmod,?_n_fmod,RDATA
	.FRAME _n_frexp,?_n_frexp,RDATA
	.FRAME _n_ldexp,?_n_ldexp,RDATA
	.FRAME _n_log10,?_n_log10,RDATA
	.FRAME _n_log,?_n_log,RDATA
	.FRAME _n_modf,?_n_modf,RDATA
	.FRAME _n_pow,?_n_pow,RDATA
	.FRAME _n_sqrt,?_n_sqrt,RDATA
	.FRAME _n_tan,?_n_tan,RDATA
	.FRAME _n_tanh,?_n_tanh,RDATA
	.FRAME _n__u_dtoe,?_n__u_dtoe,RDATA
	.FRAME _n__u_dtof,?_n__u_dtof,RDATA
	.FRAME _n__u_dtog,?_n__u_dtog,RDATA
	.FRAME _n__u_flt_info,?_n__u_flt_info,RDATA
	.FRAME _n__u_flt_rnd,?_n__u_flt_rnd,RDATA
	.FRAME _n_strtod,?_n_strtod,RDATA
	.FRAME _n___fprint_send,?_n___fprint_send,RDATA
	ENDIF
		END
