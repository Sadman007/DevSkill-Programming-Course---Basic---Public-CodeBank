#include <bits/stdc++.h>
using namespace std;

bool checkBit(int n, int pos)
{
    return n & (1 << pos);
}

bool isValid(vector<int>&subset, int target)
{
    int sum = 0;
    for(auto it : subset) sum += it;
    return sum == target;
}

int main()
{
    int n, t;
    while(scanf("%d %d", &t, &n) == 2)
    {
        if(t == 0 && n == 0) break;
        vector<int>arr(n, 0);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        set<vector<int>>comb;
        /// arr = {1, 2, 3}
        /// comb = {{1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}}
        for(int bitmask = 1; bitmask < (1 << n); bitmask++) /// 1...4095
        {
            vector<int>subset;
            /// bitmask = 12 /// 1100
            for(int i = 0; i < n; i++)
            {
                if(checkBit(bitmask, i))
                {
                    subset.push_back(arr[i]);
                }
            }
            sort(subset.rbegin(), subset.rend());
            comb.insert(subset);
        }
        printf("Sums of %d:\n", t);
        stack<vector<int> > stk;
        for(auto subset : comb)
        {
            if(isValid(subset, t))
            {
                stk.push(subset);
            }
        }
        bool isAny = stk.size() > 0;
        while(!stk.empty())
        {
            auto subset = stk.top();
            stk.pop();
            for(int i = 0; i < subset.size(); i++)
            {
                if(i) printf("+");
                printf("%d", subset[i]);
            }
            printf("\n");
        }
        if(isAny == false) puts("NONE");
    }
    return 0;
}
