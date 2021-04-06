// CMPT 295 Assignment 2 Four-bit Full Adder
// DO NOT include a main function in your final submission.

#include <stdio.h>

typedef char bit;

// Adders return a sum and carry-out. Sum may be multiple bits in size, but carry-out is
// always one bit in size.
typedef struct 
{
    int sum;
    bit carryOut;
} adderReturn;

// Implements the half adder logic from class. 
// PRE: the bits to be added are in the least significant bit of x and y
// POST: the sum and carry-out of adding the two bits is returned
adderReturn halfAdder(bit x, bit y)
{
		adderReturn output;
		output.sum = x^y;
		output.carryOut = x&y;

		return output;
}

// Implements the full adder logic from class, using two half-adders. 
// PRE: the bits to be added are in the least significant bit of x, y, and carryIn
// POST: the sum and carry-out of adding the three bits is returned
adderReturn fullAdder(bit x, bit y, bit carryIn)
{
    adderReturn output;
	output.sum = halfAdder(halfAdder(x, y).sum, carryIn).sum;
	output.carryOut = halfAdder(halfAdder(x, y).sum, carryIn).carryOut | halfAdder(x, y).carryOut;

    return output;
}

// Implements a four-bit full adder using multiple calls to the fullAdder function.
// PRE: the least significant four-bits of a and b contain the numbers to be added,
//      and the least significant bit of carryIn contains the carry-in to be used
// POST: the four-bit sum and single-bit carry-out is returned. Note that the carry-out
//       signals whether overflow occurred.
adderReturn fourBitAdder(int a, int b, bit carryIn)
{
	bit a1, a2, a3, a4;//first four-bit number
	a1 = a & 1;
	a2 = (a >> 1) & 1;
	a3 = (a >> 2) & 1;
	a4 = (a >> 3) & 1;
	bit b1, b2, b3, b4;//second four-bit number
	b1 = b & 1;
	b2 = (b >> 1) & 1;
	b3 = (b >> 2) & 1;
	b4 = (b >> 3) & 1;
	adderReturn A, B, C, D;//four result for four fullAdder
	A = fullAdder(a1, b1, carryIn);
	B = fullAdder(a2, b2, A.carryOut);
	C = fullAdder(a3, b3, B.carryOut);
	D = fullAdder(a4, b4, C.carryOut);
	
	adderReturn output;
	//insert the carryout value
	output.carryOut = D.carryOut;

	//insert the result from four fullAdder
	output.sum = D.sum;//D for fourth bit

	output.sum = output.sum << 1;//C for third bit
	output.sum = output.sum | C.sum;

	output.sum = output.sum << 1;//B for second bit
	output.sum = output.sum | B.sum;

	output.sum = output.sum << 1;//A for first bit
	output.sum = output.sum | A.sum;

	return output;
}
