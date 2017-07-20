#include "SumOfTwoIntegers.h"

// Since for two bit unit, we can get the result of them with operation '^', and carry of them with operation '&'.
// 1). Get the result of operation '^' and '&': ret and carry;
// 2). Shif left for carry, and then get new result of '^' and '&' for ret and carry;
// 3). Loop util carry is ZREO.
int Solution::getSum (int a, int b) 
{
    if (a == 0) 
    {
        return b;
    }

    if (b == 0) 
    {
        return a;
    }

    if (a == 0 && b == 0) 
    {
        return 0;
    }

    int carry = 0;

    while (b) 
    {
        carry = a & b;
        a = a ^ b;

        b = carry << 1;
    }

    return a;
}
