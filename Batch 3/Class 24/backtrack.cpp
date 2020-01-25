#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

/// problem 1 : given N, output the sum of 1^1 + 2^2 + 3^3 + ... + n^n
ll po(int a,int b)
{
    ll s = 1;
    while(b--) s*=a;
    return s;
}

ll f(int n)
{
    if(n == 1) return 1;
    return po(n,n) + f(n - 1);
}

/// problem 2 : reverse a queue using recursion
void makeReverse(queue<int>&q)
{
    if(q.empty()) return;
    int v = q.front();
    q.pop();
    makeReverse(q);
    q.push(v);
}

/// problem 3 : subset
vector<int>v({1,2,2,3});
int S;

void getSubset(int index, vector<int>subset)
{
    if(index == v.size())
    {
        int s = accumulate(subset.begin(),subset.end(),0);
        if(2*s == S) cout << "YAHOOOOO SOLUTION PEYE GESI!\n";
        return;
    }
    getSubset(index + 1,subset);
    subset.push_back(v[index]);
    getSubset(index + 1,subset);
}

int main()
{
    S = accumulate(v.begin(),v.end(),0);
    getSubset(0,vector<int>());
    return 0;
}
