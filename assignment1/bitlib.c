#include <stdio.h>

typedef unsigned int bit32;
bit32 get_byte(bit32 , int);
bit32 place_byte(bit32 , bit32, int);
void printhex();


void printhex(bit32 x)
{
    printf("%.8x ", x);
}

bit32 get_byte(bit32 hex_val, int n)
{
    bit32 sol;
    if(n == 0)
    {
        sol = hex_val & 0x000000ff;
        return sol;
    }
    if(n == 1)
    {
        sol = hex_val & 0x0000ff00;
        sol = sol >> 8;
        return sol;
    }
    if(n == 2)
    {
        sol = hex_val & 0x00ff0000;
        sol = sol >> 16;
        return sol;
    }
    if(n == 3)
    {
        sol = hex_val & 0xff000000;
        sol = sol >> 24;
        return sol;
    }

}
bit32 place_byte(bit32 hex_val, bit32 byte_val, int n)
{
    bit32 sol;
    if(n == 0)
    {
        sol = hex_val | byte_val;
        return sol;
    }
    if(n == 1)
    {
        byte_val = byte_val << 8;
        sol = hex_val | byte_val;
        return sol;
    }
    if(n == 2)
    {
        byte_val = byte_val << 16;
        sol = hex_val | byte_val;
        return sol;
    }
    if(n == 3)
    {
        byte_val = byte_val << 24;
        sol = hex_val | byte_val;
        return sol;
    }

}
