#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, s, sum = 0;
        scanf("%d %d",&n, &s);
        vector<int>arr(n);
        unordered_map<int, int> last;
        last[0] = -1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int max_len = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (last.count(sum - s))
            {
                max_len = max(max_len, i - last[sum - s] + 1);
            }
            if (last.count(sum) == 0)
            {
                last[sum] = i;
            }
        }
        if (sum < s) printf("-1\n");
        else printf("%d\n", n - max_len);
    }
    return 0;
}
