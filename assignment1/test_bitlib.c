#include <stdio.h>
typedef unsigned int bit32;
void printhex();
bit32 sign(bit32);
bit32 expon(bit32);
bit32 frac(bit32);
bit32 float_32(bit32, bit32, bit32);
bit32 fp_add(bit32, bit32);

int main()
{
	bit32 x = 0x42AA4000;
	bit32 y = 0x41220000;
	bit32 add = fp_add(x, y);
	printf("addition = %d\n", add);
	return 0;
}

