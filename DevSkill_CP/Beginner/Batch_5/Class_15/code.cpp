#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

/// 1, 2, 3, 4, 5 -> inversion count = 0
/// 5, 4, 3, 2, 1 -> inversion count = 10, (i < j , arr[i] > arr[j])

void insertion_sort(vector<int>&arr)
{
    int steps = 0;
    int n = arr.size();
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int p = i - 1;
        steps++;
        while(p >= 0 && arr[p] > key)
        {
            steps++;
            arr[p + 1] = arr[p];
            p--;
        }
        arr[p + 1] = key;
    }
    cout << "TOTAL NUMBER OF STEPS: " << steps << "\n";
}

int main()
{
    /// 1 5 7 []    3 5 [10]
    /// 1 3 5 5 7 10
    vector<int>arr{1,2,3,4,5,6,7,8,9,10};
    insertion_sort(arr);
    for(auto it : arr)
        cout << it << " ";
    return 0;
}
