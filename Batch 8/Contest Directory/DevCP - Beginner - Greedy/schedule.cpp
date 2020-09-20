#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<pair<int, int> > work;
stack<int>stk;

int main()
{
    //freopen("in.txt","r",stdin);
    int T, n, L, R;
    scanf("%d", &T);
    while(T--)
    {
        long long tot = 0;
        scanf("%d", &n);
        work.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &L, &R);
            work.push_back({L, +1});
            work.push_back({R, -1});
            tot += R - L;
        }
        sort(work.begin(), work.end());
        while(!stk.empty()) stk.pop();
        int simultaneous_work = 0;
        int max_machine = 0;
        for(int i = 0; i < (int)work.size(); i++)
        {
            if(work[i].second == 1)
            {
                ++simultaneous_work;
                if(!stk.empty())
                {
                    int top = stk.top();
                    stk.pop();
                    tot += work[i].first - top;
                }
            }
            else
            {
                --simultaneous_work;
                stk.push(work[i].first);
            }
            max_machine = max(max_machine, simultaneous_work);
        }
        printf("%d %lld\n", max_machine, tot);
    }

    return 0;
}