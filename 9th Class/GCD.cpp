#include <bits/stdc++.h>
using namespace std;

///iterative
int gcd(int a,int b)
{
    int mod;
    while(1)
    {
        mod = a%b;
        if(mod==0) return b;
        a = b;
        b = mod;
    }
}
/// recursive
int rgcd(int a,int b)
{
    if(!b) return a;
    return rgcd(b,a%b);
}

int main()
{
    cout << rgcd(30,12);
    return 0;
}

