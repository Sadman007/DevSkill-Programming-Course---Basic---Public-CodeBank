#include <bits/stdc++.h>
using namespace std;
void QuickSort(int *arr,int lo,int hi)
{
    int pvt = arr[(lo+hi)/2];
    int L = lo;
    int R = hi;
    while(L<=R)
    {
        while(arr[L] < pvt) L++;
        while(arr[R] > pvt) R--;
        if(L <= R)
        {
            swap(arr[L],arr[R]);
            L++;
            R--;
        }
    }
    if(lo<R) QuickSort(arr,lo,R);
    if(L<hi) QuickSort(arr,L,hi);
}
int main()
{
    int n,arr[100];
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    random_shuffle(arr,arr+n);
    QuickSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    return 0;
}
