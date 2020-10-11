#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 200000

ll M[MAX + 5];
vector<int>gr[2][MAX + 5];
int h[2][MAX + 5];

void dfs(int type, int u = 0, int pr = -1) /// type 0 for 1st tree, type 1 for 2nd tree
{
    if(pr != -1) h[type][u] = h[type][pr] + 1;
    for(auto &v : gr[type][u])
    {
        if(v != pr)
            dfs(type, v, u);
    }
}

ll getHash(int type, int u = 0, int pr = -1)
{
    if(gr[type][u].empty()) return 1LL;
    ll res = 1LL;
    for(auto &v : gr[type][u])
    {
        if(v != pr)
            res = (res * (M[h[type][u]] + getHash(type, v, u))) % MOD;
    }
    return res;
}

int main()
{
    for(int i = 0; i < MAX; i++) M[i] = (1LL * rand() * rand()) % MOD;
    int n1, n2, u, v;
    cin >> n1;
    for(int i = 0; i < n1 - 1; i++)
    {
        cin >> u >> v;
        gr[0][u].push_back(v);
        gr[0][v].push_back(u);
    }
    cin >> n2;
    for(int i = 0; i < n2 - 1; i++)
    {
        cin >> u >> v;
        gr[1][u].push_back(v);
        gr[1][v].push_back(u);
    }
    dfs(0);
    dfs(1);
    if(getHash(0) == getHash(1)) cout << "Isomorphic\n";
    else cout << "Non-Isomorphic\n";
    return 0;
}
/**
Sample case for two Isomorphic trees
6
0 1
0 2
0 3
1 4
1 5
6
0 1
0 2
0 3
2 4
2 5

        0
      / \ \
     1   2 3
    / \
   4   5

         0
       / \ \
      1   2 3
         / \
        5   4

**/
