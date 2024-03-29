#include <stdio.h>

typedef unsigned int bit32;
void printhex(bit32);
bit32 sign(bit32);
bit32 expon(bit32);
bit32 frac(bit32);
bit32 float_32(bit32, bit32, bit32);
bit32 fp_add(bit32, bit32);

bit32 fp_add(bit32 x, bit32 y)
{
	if (x == 0)
		return y;
	if (y == 0)
		return x;
	bit32 addition;
	bit32 exp_x = expon(x);
	printf("exp_x = %d\n", exp_x);
	bit32 exp_y = expon(y);
	printf("exp_y = %d\n", exp_y);
	bit32 exp_max;
	bit32 exp_xy;
	bit32 frac_x = frac(x);
	printf("frac_x = %d\n", frac_x);
	bit32 frac_y = frac(y);
	printf("frac_y = %d\n", frac_y);
	bit32 frac_add;
	//Compare the exponents of the two numbers
	if (exp_x > exp_y)
	{
	//shift the smaller number to the right
		exp_max = exp_x;
		printf("exp_max = %d\n", exp_max);
		exp_xy = exp_x - exp_y;
		printf("exp_xy = %d\n", exp_xy);
		frac_y = frac_y >> 1;
		printf("frac_y >> 1 = %d\n", frac_y);
		frac_y = frac_y + 4194304;
		printf("frac_y + 0x80000000 = %d\n", frac_y);
		if (exp_xy != 1)
			frac_y = frac_y >> (exp_xy - 1);
		printf("frac_y >> many = %d\n", frac_y);
	}
	//Compare the exponents of the two numbers
	if (exp_x < exp_y)
	{
	//shift the smaller number to the right
		exp_max = exp_y;
		exp_xy = exp_y - exp_x;
		frac_x = frac_x >> 1;
		frac_x = frac_x + 4194304;
		printf("frac_x = %d\n", frac_y);
		if (exp_xy != 1)
			frac_x = frac_x >> (exp_xy - 1);
	}
	frac_add = frac_x + frac_y;
	printf("frac_add = %d\n", frac_add);
	if (frac_add == 0)
		return 0;
	//normalize the sum if needed
	if (frac_add > 0xffffffff)
	{
		frac_add = frac_add >> 1;
		exp_max = exp_max + 1;
	}
	addition = float_32(0, exp_max, frac_add);
	return addition;
}

bit32 float_32(bit32 sign, bit32 exp, bit32 frac)
{
	bit32 fp = 0;
	exp = exp + 127;
	fp = fp | sign;
	fp = fp << 8;
	fp = fp | exp;
	fp = fp << 23;
	fp = fp | frac;
	return fp;
}


bit32 sign(bit32 x)
{
	x = x & 0xf0000000;
	x = x >> 28;
	if (x < 8)
		return 0;
	else
		return 1;
}

bit32 expon(bit32 x)
{
	x = x >> 23;
	x = x & 0x000000ff;
	x = x - 127;
	return x;
}

bit32 frac(bit32 x)
{
	x = x & 0x00ffffff;
	x = x << 1;
	x = x & 0x00ffffff;
	x = x >> 1;
	return x;
}

void printhex(bit32 x)
{
	printf("%.8x ", x);
}