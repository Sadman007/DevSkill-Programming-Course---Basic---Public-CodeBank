#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int num)
{
    int status = num & (num - 1);
    if(status == 0) return true;
    else return false;
}

int main()
{
    for(int i = 1; i <= 100; i++)
    {
        if(isPowerOfTwo(i) == true) cout << i << "\n";
    }
    int var = 13;
    for(int i = 30; i >= 0; i--)
    {
        int status = var & (1 << i);
        /**status will be 0 if the i-th bit of var is 0,
         otherwise the value of status will be non-zero.
         **/
        if(status == 0) printf("0");
        else printf("1");
    }
    return 0;
}
