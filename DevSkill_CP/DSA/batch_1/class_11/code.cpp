#include <bits/stdc++.h>
using namespace std;
int arr[1000];

bool binarySearch(int n, int v)
{
    int L = 0, R = n - 1;
    while(L <= R)
    {
        int M = (L + R) / 2;
        if (arr[M] == v)
        {
            return true;
        }
        else if (arr[M] < v)
        {
            L = M + 1;
        }
        else
        {
            R = M - 1;
        }
    }
    return false;
}

int main()
{
    int v, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cin >> v;
    if (binarySearch(n, v) == true)
    {
        cout << "YES!";
    }
    else
    {
        cout << "NO...";
    }
    return 0;
}
