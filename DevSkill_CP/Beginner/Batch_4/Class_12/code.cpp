#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>&arr)
{
    int n = arr.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    vector<int>vc{5,1,0,2,1,3,7,2};
    bubble_sort(vc);
    for(int v : vc)
        cout << v << " ";
    return 0;
}
