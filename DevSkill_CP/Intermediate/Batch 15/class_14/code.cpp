#include <bits/stdc++.h>
using namespace std;

/// expectation: Given that, arr[L...M] and arr[M + 1...R] are already sorted,
/// merge_them() merges arr[L...M] and arr[M + 1...R] into arr[L...R] as a sorted
/// array.
void merge_them(vector<int> &arr, int L, int R)
{
    int M = (L + R) / 2;
    int *temp = new int[R - L + 1];
    int p1 = L, p2 = M + 1;

    int idx = 0;
    while(p1 <= M && p2 <= R)
    {
        if (arr[p1] <= arr[p2])
        {
            temp[idx++] = arr[p1];
            p1++;
        }
        else
        {
            temp[idx++] = arr[p2];
            p2++;
        }
    }
    while(p1 <= M)
    {
        temp[idx++] = arr[p1];
        p1++;
    }
    while(p2 <= R)
    {
        temp[idx++] = arr[p2];
        p2++;
    }
    for (int i = 0; i < (R - L + 1); i++)
    {
        arr[L + i] = temp[i];
    }
}

/// expectation: mergeSort() sorts arr[L...R]
void mergeSort(vector<int> &arr, int L, int R)
{
    if (L >= R) return;
    int M = (L + R) / 2;
    mergeSort(arr, L, M); /// arr[L...M]
    mergeSort(arr, M + 1, R); /// arr[M + 1...R]
    /// now, both parts are sorted.
    merge_them(arr, L, R);
}

void mergeSort(vector<int> &arr)
{
    mergeSort(arr, 0, (int)arr.size() - 1);
}

mt19937 rng(0);
/// n = 10^6, 1.26s
/// n = 10^6, 0.43s
int main()
{
    int n = 1000000;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rng() % INT_MAX;
    }
    mergeSort(arr);
    assert(is_sorted(arr.begin(), arr.end()));
    return 0;
}
