#include <bits/stdc++.h>
using namespace std;

int n,pr[100000];

int find_set(int u)
{
    if(u == pr[u]) return u;
    return pr[u] = find_set(pr[u]);
}

void union_set(int u,int v)
{
    int pu = find_set(u);
    int pv = find_set(v);
    if(pu != pv)
    {
        pr[pu] = pv;
    }
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) pr[i] = i;

    int q;
    cin >> q;

    while(q--)
    {
        int com;
        cin >> com;
        if(com == 0)
        {
            int u;
            cin >> u;
            cout << "parent of " << u << " is " << find_set(u) << "\n";
        }
        else
        {
            int u,v;
            cin >> u >> v;
            union_set(u,v);
        }
        puts("parent array is : ");
        for(int i=1;i<=n;i++)
        {
            printf("%d ",pr[i]);
        }
        puts("");
    }

    return 0;
}
