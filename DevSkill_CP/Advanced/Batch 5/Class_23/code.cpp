#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define MAX 1005
#define base 257
char str[MAX + 5];
ull po[MAX + 5], prefix_hash[MAX + 5];

void pre()
{
    po[0] = 1;
    for(int i = 1; i <= MAX; i++)
    {
        po[i] = po[i - 1] * base;
    }
}

void genHash(int n)
{
    prefix_hash[0] = str[0];
    for(int i = 1; i < n; i++)
    {
        prefix_hash[i] = (prefix_hash[i - 1] * base) + str[i];
    }
}

ull getHash(int L, int R)
{
    if(!L) return prefix_hash[R];
    return prefix_hash[R] - (prefix_hash[L - 1] * po[R - L + 1]);
}

int main()
{
    vector<int>arr(20);
        for(int i = 0; i < 20; i++)
            arr[i] = i;

    int tryy = 1000;
    int cnt = 0;
    while(tryy--)
    {
        random_shuffle(arr.begin(), arr.end());
        int pos = -1;
        for(int i = 0; i < 20; i++)
        {
            if(arr[i] == 19)
            {
                pos = i;
                break;
            }
        }
        cnt += pos;
    }
    cout << setprecision(6) << fixed << 1.00 * cnt / 1000;
    return 0;
}
