#include <bits/stdc++.h>
using namespace std;

int po(int a,int b)
{
    int s = 1;
    while(b--) s*=a;
    return s;
}

int checkBit(int n,int pos)
{
    int k = 1<<pos; /// 2^pos O(1)
    return n&k;
    /**
    left shift :
    0001 = 1 = 2^0
    0010 = 2 = 2^1
    0100 = 4 = 2^2
    1000 = 8 = 2^3
    .. .. .. 2^k = 1<<k


    right shift
    1000
    0100
    0010
    0001
    **/
}

void printBinary(int n)
{
    for(int i=15;i>=0;i--)
    {
        if(checkBit(n,i)==0) printf("0");
        else printf("1");
    }
}

int main()
{
    int v;
    /**
        each integer variable consists of exactly 32 bits.
        [0]0000000 00000000 00000000 00000000
        left most bit = sign bit
        sign bit 0 = positive number
        sign bit 1 = negative number
        int range 2^31 ta different number represent korte pare
        0 ~ (2^31 - 1)
        0 ~ 2147483647
    **/
    int n = 181;
    printBinary(n);
    return 0;
}
