#include <bits/stdc++.h>
using namespace std;

int COUNT = 0;
int arr[1000000];

void QuickSort(int *arr,int lo,int hi) /// sort the array "arr" from index "lo" to "hi" inclusive
{
    int pivot = arr[(lo+hi)/2];
    int L = lo;
    int R = hi;

    while(L<=R)
    {
        COUNT++;
        while(arr[L]<pivot) L++;
        while(arr[R]>pivot) R--;
        if(L<=R)
        {
            swap(arr[L],arr[R]);
            L++,R--;
        }
    }

    if(lo<R) QuickSort(arr,lo,R);
    if(L<hi) QuickSort(arr,L,hi);
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) arr[i] = i+1;

    QuickSort(arr,0,n-1);

    //for(int i=0;i<n;i++) cout << arr[i] << " "; cout << endl;
    cout << COUNT << endl;
    return 0;
}
