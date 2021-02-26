#include <bits/stdc++.h>
using namespace std;

void CountingSort(vector<int>&arr)
{
    int low = *min_element(arr.begin(), arr.end()); /// L = 1
    int high = *max_element(arr.begin(), arr.end()); /// R = 3
    vector<int>freq(high - low + 1, 0);

    for(auto elem : arr) /// arr = {2,3,2,2,1}
        freq[elem]++;

    /// freq = {0, 1, 3, [1]}
    int ind = 0; /// arr = {1, 2, 2, 2, 3} []
    for(int value = low; value <= high; value++) /// value = 3
    {
        int cnt = freq[value]; /// cnt = 1 //freq[3]
        while(cnt--)
        {
            arr[ind++] = value;
        }
    }
}

bool isValid(vector<int>&arr)
{
    int n = arr.size();
    for(int i = 0; i + 1 < n; i++)
    {
        if(arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    CountingSort(arr);
    bool validity = isValid(arr);
    if(validity) puts("OK");
    else puts("NOT OK");

    return 0;
}
