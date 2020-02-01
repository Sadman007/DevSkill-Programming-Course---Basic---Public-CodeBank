#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000000000000LL
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

vector<ll>ugly;
unordered_map<ll,int>dp;

void gen(ll N)
{
    if(N > MAX) return;

    if(dp.find(N)!=dp.end()) return; /// if(dp[N] == 1) return;
    dp[N] = 1;

    ugly.push_back(N);
    gen(2*N);
    gen(3*N);
    gen(5*N);
}

int main()
{
    gen(1);
    sort(ugly.begin(),ugly.end());
    cout << ugly[1499] << endl;
    return 0;
}

