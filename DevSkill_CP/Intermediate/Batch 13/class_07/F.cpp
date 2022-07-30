#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int elem;
        long long cnt = 0;
        vector<int> pos;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &elem);
            if (elem < i)
            {
                cnt += lower_bound(pos.begin(), pos.end(), elem) - pos.begin();
                pos.push_back(i);
            }
        }
        printf("%lld\n", cnt);
    }
    return 0;
}
