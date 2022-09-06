#include <bits/stdc++.h>
using namespace std;
mt19937 rng(0);

int createPartition(vector<int> &nums, int L, int R)
{
    int pivot = nums[R];
    int i = L - 1;
    for (int j = L; j < R; j++)
    {
    {
        if (nums[j] <= pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[R]);
    return i + 1;
}

/// sorts the vector `nums` in [L, R] range.
void quickSort(vector<int> &nums, int L, int R)
{
    if (L < R)
    {
        int p = createPartition(nums, L, R); /// [L, R] --> [vi] <= nums[p] <= [vj]
        quickSort(nums, L, p - 1);
        quickSort(nums, p + 1, R);
    }
}

int main()
{
    int n = 1000000;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) nums[i] = i;
    shuffle(nums.begin(), nums.end(), rng);
    quickSort(nums, 0, nums.size() - 1);
    if(is_sorted(nums.begin(), nums.end())) puts("CORRECT");
    else puts("NOT CORRECT");
    return 0;
}

