#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006

int freq[2*MAX];

void CountingSort(int *arr,int n) ///O(n)
{
    int mn = arr[0];
    int mx = arr[0];
    /// update the frequency of each item
    /// find out the min value and max value
    for(int i=0;i<n;i++)
    {
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }
    int OFFSET = 0;
    if(mn < 0) OFFSET = (-1) * mn;
    mn = mn + OFFSET;
    mx = mx + OFFSET;

    for(int i=0;i<n;i++)
    {
        freq[arr[i]+OFFSET]++;
    }
    int idx = 0;
    for(int v=mn;v<=mx;v++)
    {
        while(freq[v]-- > 0)
        {
            arr[idx] = v-OFFSET;
            idx++;
        }
    }
}

void CountingSort_hash(int *arr,int n)
{
    unordered_map<int,int>fr;
    int mn = arr[0];
    int mx = arr[0];
    for(int i=0;i<n;i++)
    {
        fr[arr[i]]++;
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }
    int idx = 0;
    for(int v=mn;v<=mx;v++)
    {
        if(fr.find(v) == fr.end()) continue;
        while(fr[v]-- > 0)
        {
            arr[idx] = v;
            idx++;
        }
    }
}

int main()
{
    int arr[10],n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    CountingSort_hash(arr,n);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    return 0;
}
