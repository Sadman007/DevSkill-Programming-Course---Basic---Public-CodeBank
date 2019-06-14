#include <bits/stdc++.h>
using namespace std;

int main()
{
    /// ekta code 1 second e 10^8 ta task complete korte pare
    /// 10^8 ta task e lagbe 1 second
    /// 1 ta task e lagbe 1/10^8 second
    /// 10^6 ta task e lagbe 10^6/10^8 second = 10^-2 second = 0.01 second
    int execution = 0;
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
        {
            execution++;
        }
    }
    printf("%d\n",execution);
    int a = 2147483647+3;
    printf("value of a %d\n",a);
    return 0;
}
/**

int : RANGE : (-2^31) theke (+2^31)-1

**/
