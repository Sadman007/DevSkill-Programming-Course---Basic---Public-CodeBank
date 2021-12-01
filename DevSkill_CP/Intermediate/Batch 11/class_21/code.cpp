#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
vector<int> arr;
int n;

bool check(int L, int R, int x)
{
    while(L < R)
    {
        if (arr[L] == arr[R]) L++, R--;
        else if (arr[L] == x) L++;
        else if (arr[R] == x) R--;
        else return false;
    }
    return true;
}

bool solve()
{
    scanf("%d", &n);
    arr.clear();
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int L = 0, R = arr.size() - 1;
    while(L < R)
    {
        if (arr[L] == arr[R]) L++, R--;
        else
        {
            return check(L, R, arr[L]) || check(L, R, arr[R]);
        }
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        if (solve()) puts("YES");
        else puts("NO");
    }
    return 0;
}
