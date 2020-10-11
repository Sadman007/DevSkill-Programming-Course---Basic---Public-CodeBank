#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

int maxSumSubArray(vector<int>&A)
{
    int n = A.size();
    int local_max = 0;
    int global_max = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        local_max = max(A[i], A[i] + local_max);
        global_max = max(global_max, local_max);
    }
    return global_max;
}

int main()
{
    vector<int>A{-1,2,-3};
    cout << maxSumSubArray(A);
    return 0;
}

