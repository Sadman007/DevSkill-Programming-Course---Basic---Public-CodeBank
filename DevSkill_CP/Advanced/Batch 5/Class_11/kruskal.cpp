#include <bits/stdc++.h>
using namespace std;
#define MAX 200000
#define piii pair<int, pair<int, int> >

int pr[MAX + 5];
int findP(int u)
{
    if(u == pr[u]) return u;
    return pr[u] = findP(pr[u]);
}
void connect(int u, int v)
{
    int pu = findP(u);
    int pv = findP(v);
    if(pu != pv)
        pr[pv] = pu;
}
/// O(MlogM)
int getMST(vector<piii>&vedge, int n, bool minimum = true)
{
    for(int i = 0; i < n; i++)
        pr[i] = i;
    sort(vedge.begin(), vedge.end());
    if(!minimum)
        reverse(vedge.begin(), vedge.end());
    int mstCost = 0;
    int cntEdge = 0;
    for(auto e : vedge)
    {
        int u = e.second.first;
        int v = e.second.second;
        int pu = findP(u);
        int pv = findP(v);
        if(pu != pv)
        {
            mstCost += e.first;
            cout << u << " ---- " << v << endl;
            connect(pu, pv);
            cntEdge++;
        }
        if(cntEdge == n - 1) break;
    }
    return mstCost;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<piii>vedge;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vedge.push_back({w, {u, v}});
    }
    cout << "MST COST : " << getMST(vedge, n, true) << endl;
    return 0;
}

/**
Sample Input:
5 7
0 1 2
1 2 20
2 3 5
3 4 1
2 4 4
1 4 3
0 4 10
**/
