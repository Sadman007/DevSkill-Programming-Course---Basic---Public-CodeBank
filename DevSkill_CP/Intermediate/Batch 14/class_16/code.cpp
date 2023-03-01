#include <bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));

long long inv_count;

void merge_arrays(vector<int> &arr, int L, int R)
{
    vector<int> temp(R - L + 1);

    int i = 0;
    int M = L + (R - L) / 2;
    int iL = L;
    int iR = M + 1;

    /// take from both arrays.
    while(iL <= M && iR <= R)
    {
        if (arr[iL] <= arr[iR])
        {
            temp[i++] = arr[iL];
            iL++;
        }
        else  /// [2, (4), 6, 8] <-----> [1, (3), 5, 7]
        {
            inv_count += M - iL + 1;
            temp[i++] = arr[iR];
            iR++;
        }
    }

    /// take everything from left.
    while(iL <= M)
    {
        temp[i++] = arr[iL];
        iL++;
    }

    /// take everything from right.
    while(iR <= R)
    {
        temp[i++] = arr[iR];
        iR++;
    }

    /// reflect the changes back to arr.
    for (int i = L; i <= R; i++)
    {
        arr[i] = temp[i - L];
    }
}

void merge_sort(vector<int> &arr, int L, int R)
{
    if (L >= R) return;
    int M = L + (R - L) / 2;
    merge_sort(arr, L, M);
    merge_sort(arr, M + 1, R);
    merge_arrays(arr, L, R);
}

void merge_sort(vector<int> &arr)
{
    inv_count = 0;
    merge_sort(arr, 0, arr.size() - 1);
    cout << "inv count " << inv_count << "\n";
}

int main()
{
    vector<int> arr;
    int n = 100000;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(n - i);
    }
    merge_sort(arr);
    if (is_sorted(arr.begin(), arr.end()))
    {
        cout << "SUCCESSFUL\n";
    }
    else
    {
        cout << "FAILED!\n";
    }
    return 0;
}
