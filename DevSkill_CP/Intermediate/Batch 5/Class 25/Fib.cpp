#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

ll fibonacci[100];

ll fib(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;

    if(fibonacci[n] != -1) return fibonacci[n];

    fibonacci[n] = fib(n-1) + fib(n-2);
    return fibonacci[n];
}

int main()
{
    memset(fibonacci,-1,sizeof fibonacci);
    cout << fib(50) << "\n";
    return 0;
}
