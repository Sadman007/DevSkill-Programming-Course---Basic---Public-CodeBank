#include <bits/stdc++.h>
using namespace std;

int n;

void printStates(int *arr,int L,int R)
{
    cout << "L " << L << " " << "R " << R << "\n";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    getchar();
}
int call = 1;

void QuickSort(int *arr,int lo,int hi)
{
    cout << " CALL " << call++ << endl;
    int pivot = arr[(lo+hi)/2];
    int L = lo;
    int R = hi;

    while(L<=R)
    {
        printStates(arr,L,R);
        while(arr[L]<pivot)
            L++;
        while(arr[R]>pivot)
            R--;
        if(L<=R)
        {
            swap(arr[L],arr[R]);
            L++,R--;
        }
    }
    if(lo<R)
        QuickSort(arr,lo,R);
    if(L<hi)
        QuickSort(arr,L,hi);
}


int main()
{
    cin >> n;
    int arr[100];
    for(int i=0;i<n;i++) cin >> arr[i];

    QuickSort(arr,0,n-1);


    return 0;
}
