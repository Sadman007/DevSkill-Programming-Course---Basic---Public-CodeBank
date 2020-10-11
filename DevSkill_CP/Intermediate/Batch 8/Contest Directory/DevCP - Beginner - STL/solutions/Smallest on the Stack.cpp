#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<pair<int, int> > stk;
    int Q, curr_min = INT_MAX / 2;
    char com[10];
    scanf("%d", &Q);
    while(Q--)
    {
        scanf("%s", com);
        if(com[0] == 'P' && com[1] == 'U') /// because PUSH!
        {
            int val;
            scanf("%d", &val);
            int new_min = val;
            if(stk.size() > 0) new_min = min(val, stk.top().second);
            stk.push(make_pair(val, new_min));
        }
        else if(com[0] == 'M')
        {
            if(stk.size() == 0) puts("EMPTY"); /// puts automatically prints a new line.
            else printf("%d\n", stk.top().second);
        }
        else /// it's for pop
        {
            if(stk.size() == 0) puts("EMPTY");
            else stk.pop();
        }
    }
    return 0;
}
