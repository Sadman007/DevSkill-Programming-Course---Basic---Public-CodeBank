#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long

int twoPower(int N)
{
    return 1 << N;
}

bool checkBit(int N,int x)
{
    if (N&(1<<x) == 0) return 0;
    return 1;
}

int findSingleNumber(int *arr,int n)
{
    int xor = 0;
    for(int i=0;i<n;i++) xor^=arr[i];
    return xor;
}

int main()
{
    /**
        file input output
        add these one/two lines (depending on what you want) just after int main()

        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    **/


    return 0;
}
