#include <bits/stdc++.h>
using namespace std;
mt19937 rng(0);

/**
mt19937 rng(0);

class Solution {
public:
    int createPartition(vector<int> &arr, int L, int R)
    {
        int pvt = arr[R];
        int i = L - 1;
        for (int j = L; j < R; j++)
        {
            if (arr[j] <= pvt)
            {
                swap(arr[i + 1], arr[j]);
                i++;
            }
        }
        /// fix pivot's position
        swap(arr[i + 1], arr[R]);
        return i + 1;
    }

    void partial_sort(vector<int> &arr, int k)
    {
        shuffle(arr.begin(), arr.end(), rng);
        int L = 0;
        int R = arr.size() - 1;
        while(L < R) {
            int p = createPartition(arr, L, R);
            if (p < k) L = p + 1;
            else if (p > k) R = p - 1;
            else break;
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        partial_sort(nums, k);
        return nums[k];
    }
};
**/


int createPartition(vector<int> &arr, int L, int R)
{
    int pvt = arr[R];
    int i = L - 1;
    for (int j = L; j < R; j++)
    {
        if (arr[j] <= pvt)
        {
            swap(arr[i + 1], arr[j]);
            i++;
        }
    }
    /// fix pivot's position
    swap(arr[i + 1], arr[R]);
    return i + 1;
}

void quickSort(vector<int> &arr, int L, int R)
{
    if (L >= R) return;
    int p = createPartition(arr, L, R);

    while(p > 0 && arr[p] == arr[p - 1]) --p;
    quickSort(arr, L, p - 1); /// [L, p - 1]

    while(p < R && arr[p] == arr[p + 1]) ++p;
    quickSort(arr, p + 1, R); /// [p + 1, R]
}

void quickSort(vector<int> &arr)
{
    shuffle(arr.begin(), arr.end(), rng);
    quickSort(arr, 0, arr.size() - 1);
}

int main()
{
    int n = 5000000;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rng() % 1000000;
    }
    quickSort(arr);
    cout << is_sorted(arr.begin(), arr.end()) << "\n";
    return 0;
}
