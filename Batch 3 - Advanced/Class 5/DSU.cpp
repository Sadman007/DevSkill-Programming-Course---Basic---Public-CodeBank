#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

int N, par[MAX + 5];

int find_parent(int u)
{
    if(u == par[u]) return u;
    return par[u] = find_parent(par[u]);
}

void merge_node(int u, int v)
{
    int pu = find_parent(u);
    int pv = find_parent(v);
    if(pu != pv) par[pu] = pv;
}

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++) par[i] = i; /// init
    while(1)
    {
        int q,a,b;
        cin >> q;
        if(q == 1)
        {
            cin >> a >> b;
            merge_node(a,b);
            for(int i = 1; i <= N; i++) cout << i << " : " << par[i] << "\n";
            cout << "\n";
        }
        else
        {
            cin >> a;
            cout << "parent of " << a << " is " << find_parent(a) << "\n";
            for(int i = 1; i <= N; i++) cout << i << " : " << par[i] << "\n";
            cout << "\n";
        }
    }
    return 0;
}
