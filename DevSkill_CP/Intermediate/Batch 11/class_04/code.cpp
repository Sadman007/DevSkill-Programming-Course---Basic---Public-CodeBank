#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

/// Time complexity: O(log2(N))
bool find_value(vector<int>&arr, int search_value)
{
    int L = 0, R = arr.size() - 1;
    while(L <= R)
    {
        int M = (L + R) / 2;
        if (arr[M] < search_value)
        {
            L = M + 1;
        }
        else if (arr[M] == search_value)
        {
            return true;
        }
        else /// >
        {
            R = M - 1;
        }
    }
    return false;
}

int main()
{
    vector<int>arr{1, 2, 2, 2, 3, 3, 3, 4};
    // cout << find_value(arr, 2);

    printf("%d\n", upper_bound(arr.begin(), arr.end(), 3) - arr.begin());
    return 0;
}
