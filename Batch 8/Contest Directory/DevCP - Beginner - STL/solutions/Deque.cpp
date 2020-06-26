#include <bits/stdc++.h>
using namespace std;


int main()
{
    deque<int>deq;
    int Q;
    scanf("%d", &Q);
    while(Q--)
    {
        int type;
        scanf("%d", &type);
        if(type == 0)
        {
            int d, val;
            scanf("%d %d", &d, &val);
            if(d == 0) deq.push_front(val);
            else deq.push_back(val);
        }
        else if(type == 1)
        {
            int pos;
            scanf("%d", &pos);
            printf("%d\n", deq[pos]);
        }
        else
        {
            int d;
            scanf("%d", &d);
            if(d == 0) deq.pop_front();
            else deq.pop_back();
        }
    }
    return 0;
}