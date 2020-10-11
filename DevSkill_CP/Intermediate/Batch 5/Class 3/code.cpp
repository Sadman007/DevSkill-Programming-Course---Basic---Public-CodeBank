#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

int main()
{
    /**
    int N;
    cin >> N;

    for(int i=1;i<=N;i=i+2) /// O(N) - Linear
    {
        /// do your task
    }

    for(int i=1;i<=N;i=i*2) /// O(log2(N)) - Logarithmic
    {
        /// do your task
    }


    for(int i=0;i<=N;i=i*2) /// O(inf)
    {
        /// do your task
    }

    for(int i = 1; i <= N; i++)
    {
        cout << i;
        if(i<N) cout << " ";
    }
    cout << endl;
    **/
    string a,b;
    cin >> b >> a;

    for(int i = 0;i < b.size(); i++)
    {
        if(b.substr(i,a.size()) == a) cout << i << endl;
    }

    return 0;
}
