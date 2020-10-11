#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> ls;
    auto it = ls.end(); /// you can also write list<long long>:: iterator it = ls.end();
    auto mt = ls.end();

    int Q;
    scanf("%d", &Q);

    while(Q--)
    {
        int cmd, x;
        scanf("%d", &cmd);
        if(cmd == 0)
        {
            scanf("%d", &x);
            ls.insert(it, x);
            advance(it, -1);
        }
        if(cmd == 1)
        {
            scanf("%d", &x);
            advance(it, x);
        }
        else if(cmd == 2)
        {
            mt = it;
            advance(it, 1);
            ls.erase(mt);
        }
        ///cout << "curr element " << *it << "\n"; /// comment this line out in order to see the current element pointed out by the pointer
    }
    for(auto v : ls)
    {
        printf("%d\n", v);
    }

    return 0;
}
