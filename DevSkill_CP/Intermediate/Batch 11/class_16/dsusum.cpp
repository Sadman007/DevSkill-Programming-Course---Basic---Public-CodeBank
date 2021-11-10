#include <bits/stdc++.h>
using namespace std;
#define MAX 1500

int pr[MAX + 5], budget[1050];

int find_parent(int u) /// 5 -> 4 -> 3 -> 2 -> [1]
{
    if (u == pr[u]) return u;
    return pr[u] = find_parent(pr[u]);
}

void unite(int u, int v)
{
    int pu = find_parent(u);
    int pv = find_parent(v);
    if (pu != pv)
        pr[pu] = pv;
}

int main()
{
    int T, n, con, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &con);
        for (int i = 1; i <= n; i++)
            pr[i] = i;
        for (int i = 1; i <= n; i++)
            scanf("%d", &budget[i]);
        for (int i = 1; i <= con; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            unite(u, v);
        }
        unordered_set<int> uniqueGroups;
        vector<int> groupSum(n + 1, 0);
        vector<int> totalSums;
        for (int i = 1; i <= n; i++)
        {
            int currParent = find_parent(find_parent(i));
            uniqueGroups.insert(currParent);
            groupSum[currParent] += budget[i];
        }
        for (auto sum : groupSum)
        {
            if (sum > 0)
            {
                totalSums.push_back(sum);
            }
        }
        sort(totalSums.begin(), totalSums.end());
        printf("Case %d: %d\n", cs++, (int)uniqueGroups.size());
        for (int i = 0; i < totalSums.size(); i++)
        {
            printf("%d", totalSums[i]);
            if (i + 1 < totalSums.size()) printf(" ");
        }
        puts("");
    }
    return 0;
}
