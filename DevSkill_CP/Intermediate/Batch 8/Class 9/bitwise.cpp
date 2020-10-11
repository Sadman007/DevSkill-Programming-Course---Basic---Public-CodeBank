#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000
/**
0) Introduction to Bitwise Operator

    ami ajke school e jabona JODI:

            1) ajke brishti hoy
        OR
            2) transportation e jhamela hoy
**/

/**
1) Shifting Operator:

    Left Shift: <<
    27 = 00000000000000000000000000011011
27(1)  = 00000000000000000000000000110110
27(2)  = 00000000000000000000000001101100
27(3)  = 00000000000000000000000011011000
27(4)  = 00000000000000000000000110110000
...
27(X)  = 11011000000000000000000000000000
27(X+1)= 10110000000000000000000000000000
27(X+2)= 01100000000000000000000000000000
27(X+3)= 11000000000000000000000000000000
27(X+4)= 10000000000000000000000000000000
27(X+5)= 00000000000000000000000000000000

    27 = 00000000000000000000000000011011
    one's_complement(27) = 11111111111111111111111111100100
    two's_complement(27) = 11111111111111111111111111100101

    int value = 27;
    value = value << 1;

    /// value * (2^X) [0<=X<=30]
    /// 23 * 16 = 23 * 2^4
    /// O(32 * 32) = O(1024)
    /// O(1)
    int value = 23;
    int X = 4;
    value = value << X; /// 23 << X = (23 * 2^X)
    cout << value;

**/

/**
2) Check if an integer is a power of 2.
    2^X = 1,2,4,8,16,32,64,128,256,....

    512 = 1000000000
    511 = 0111111111
-----------------------
512&511 = 0000000000

bool isPower_of_two(int n)
{
    int bitmask = n & (n - 1);
    return bitmask == 0;
}

**/

/**
3) Count the number of SET bits in an integer

    cout << __builtin_popcount(5) << "\n"; /// parameter type: int
    cout << __builtin_popcountll(5) << "\n"; /// parameter type: long long
**/

/**
    4) Single Number: https://leetcode.com/problems/single-number

    problem statement: You are given N integers. N is always ODD. There are (N - 1)/2 pairs of same values.
    Example:
        N = 11
        2 3 2 3 4 5 4 6 6 7 7

        2 ^ 3 = 1
        (2 ^ 3) ^ 2 = 1 ^ 2 = 3

        2 ^ 2 ^ 3 = 3
        2 ^ 3 ^ 2 = 3
        3 ^ 2 ^ 2 = 3

        2 ^ 2 ^ 3 ^ 3 ^ 4 ^ 4 ^ 5 ^ 6 ^ 6 ^ 7 ^ 7 = 5
        2 ^ 3 ^ 2 ^ 3 ^ 4 ^ 5 ^ 4 ^ 6 ^ 6 ^ 7 ^ 7 = 5

        TC: O(N)
        MC: O(N)

        TC: O(N)
        MC: O(1)
**/

int main()
{
    return 0;
}
