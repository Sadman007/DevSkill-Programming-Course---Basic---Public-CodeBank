#include <bits/stdc++.h>
using namespace std;

bool does_exist(vector<int>&arr, int elem)
{
    int L = 0, R = arr.size() - 1;
    while(L <= R)
    {
        int M = L + (R - L) / 2;
        if (arr[M] == elem) return true;
        if (arr[M] > elem) R = M - 1;
        else L = M + 1;
    }
    return false;
}

// 0 0 0 0 0 [0 0 1 1 1]
// 0 0 0 0 0
// 1 1 1 1 1
// [0 0 1 1 1 x]
// [1] -> 0
// [0] -> 1
int count_first_even_numbers(vector<int>&arr)
{
    int L = 0, R = arr.size();
    while(L < R)
    {
        int M = L + (R - L) / 2;
        if (arr[M] % 2 == 0)
        {
            L = M + 1;
        }
        else
        {
            R = M;
        }
    }
    return L;
}

double get_sqrt(double n)
{
    double L = 0, R = max(1.0, n), M;
    /// L = 0, R = 1
    /// L = 3.162277660, R = 3.162277667
    /// |L - R| = 0.000000007
    /// |L - R| > 0.00001
    while(fabs(L - R) > 1e-6)
    {
        M = L + (R - L) / 2.0;
        if ((M * M) > n)
        {
            R = M;
        }
        else
        {
            L = M;
        }
    }
    return M;
}

int main()
{
/*
    vector<int> arr = {1, 4, 4, 5, 14, 15, 16, 21, 30};
    for (auto v : {1, 2, 3, 4, 5, 6, 7})
        cout << does_exist(arr, v) << "\n";
    vector<int> arr = {1};
    cout << count_first_even_numbers(arr) << "\n";
*/
    cout << get_sqrt(0.5) << endl;
    return 0;
}
