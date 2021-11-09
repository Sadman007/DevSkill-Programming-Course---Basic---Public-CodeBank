#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); /// MUST ADD

int cnt = 0;
int perform_partition(vector<int> &arr, int L, int R)
{
    int rdIdx = L + (rng() % (R - L + 1));
    swap(arr[rdIdx], arr[R]);
    int pivot = arr[R];
    int i = L - 1;
    for (int j = L; j <= R; j++)
    {
        ++cnt;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[R]);
    return i + 1;
}

void quick_sort(vector<int> &arr, int L, int R)
{
    if (L < R)
    {
        int pivot_index = perform_partition(arr, L, R);
        quick_sort(arr, L, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, R);
    }
}

int main()
{
    vector<int> arr;
    int n = 1000000;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(i);
    }
    quick_sort(arr, 0, arr.size() - 1);
    cout << cnt << endl;
    return 0;
}
