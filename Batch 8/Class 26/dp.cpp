#include <bits/stdc++.h>
using namespace std;
int cache[100];

int fib(int n) /// O(2^n)  --> O(n) , fib(k) ; 0 <= k <= n
{
    if(n < 2) return n;
    /// Is fib(n) already in cache ->
    if(cache[n] != -1) return cache[n];

    cache[n] = fib(n - 1) + fib(n - 2); /// fib(n)
    return cache[n];
}

/// kadane's algo
int max_sum_subarray(vector<int> &arr)
{
    int n = arr.size();
    vector<int>best(n + 1);
    best[0] = arr[0];
    int res = arr[0];
    for(int i = 1; i < n; i++)
    {
        best[i] = max(arr[i], best[i - 1] + arr[i]);
        res = max(res, best[i]);
    }
    return res;
}

int main()
{
    /*
    memset(cache, -1, sizeof(cache));
    cout << fib(35) << "\n";
    */
    vector<int>arr{1,2,3,4};
    cout << max_sum_subarray(arr) << "\n";
    return 0;
}
