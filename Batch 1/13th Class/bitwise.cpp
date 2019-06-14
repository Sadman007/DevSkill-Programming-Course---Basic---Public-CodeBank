#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

/// is power of 2
bool is2po(int val)
{
    return (val&(val-1)) == 0;
}

bool setBit(int val,int pos)
{
    return (val|(1<<pos));
}

int checkBit(int val,int pos)
{
    return (val&(1<<pos));
}

/// bitwise sieve starts
bitset<100000010>isP;

void sieve()
{
    isP.reset();
    for(int i=2;i*i<=100000000;i++)
    {
        if(isP[i]==0)
        {
            for(int j=i*i;j<=100000000;j+=i)
            {
                isP[j] = 1;
            }
        }
    }
}

/// bitwise sieve ends

int main()
{
    auto st = high_resolution_clock::now();
    sieve();
    auto en = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(en - st);
    cout << duration.count()/1000.0 << "\n";
    /*
    for(int i=1; i<=100; i++)
    {
        if(is2po(i))
            printf("%d\n",i);
    }
    */

    string str = "abc";
    /// nC0 + nC1 + nC2 + ... + nCn = 2^n
    /**

    ""
    a
    b
    c
    ab
    bc
    ac
    abc


    for(int num=0;num<(1<<str.size());num++) /// O(n * 2^n)
    {
        for(int bit=0;bit<str.size();bit++)
        {
            if(checkBit(num,bit)) cout << str[bit] << " ";
        }
        puts("");
    }
    **/

    /**
    a<<0 = 2^0 *a
    a<<1 = 2^1 *a
    a<<2 = 2^2 *a
    a<<3 = 2^3 *a
    ...
    ...
    a<<n = 2^n *a
    1<<n = 2^n
    **/
    /**
    a>>0 = a/2^0
    a>>1 = a/2^1
    a>>2 = a/2^2
    a>>3 = a/2^3
    ...
    ...
    a>>n = a/(2^n)

    16 = 10000
  16-1 = 01111
  16&15 = 00000
    **/


    return 0;
}
