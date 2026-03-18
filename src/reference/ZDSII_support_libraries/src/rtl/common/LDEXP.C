/************************************************************************/
/*                                                                      */
/*                      Copyright (C)1987-2008 by                       */
/*                              Zilog, Inc.                             */
/*                                                                      */
/*                          San Jose, California                        */
/*                                                                      */
/************************************************************************/

#include <math.h>

typedef union
{
    float             value;
    unsigned long     bits;
} Ieee754;

enum
{   //  The IEEE 754 format is:
    //  SEEEEEEE EMMMMMMM MMMMMMMM MMMMMMMM
    //  (with an implicit mantissa high-order 1-bit.)
    mastissa_shift = 0,
    mastissa_bits  = 23,
    exponent_bits  = 8,
    exponent_shift = mastissa_shift + mastissa_bits,
    sign_shift     = exponent_shift + exponent_bits,
    exponent_mask  = (1 << exponent_bits) -1,  // shifted = 0x7F800000
    exponent_max   = (1 << exponent_bits) -1,
    exponent_base  = 127,
    exponent_min   = 0
};

// ldexp - Standard C library routine
// ldexp returns the argument multiplied by an integral (positive or
// negative) power of two.
//
// Arguments:
//   value - the floating point argument
//   power - the power of two to be used
//
// Returns:
//   - the argument multiplied by an integral power of two
//
double ldexp( double value, int power )
{
    Ieee754 floating;
    int     exponent;

    floating.value = value;
    exponent = (floating.bits >> exponent_shift) & exponent_mask;
    if ( power > exponent_max - exponent )
    {
        return (floating.bits & (1L << sign_shift)) == 0 ? HUGE_VAL : - HUGE_VAL;
    }
    if ( power < exponent_min - exponent )
    {
        return 0.0;
    }
    floating.bits += (long) power << exponent_shift;  // adjust exponent
    return floating.value;
}
