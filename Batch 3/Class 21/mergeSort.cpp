#include <bits/stdc++.h>
using namespace std;

int inv_cnt = 0;

void Merge(int arr[],int L,int mid,int R)
{
    int n1 = mid - L + 1; /// size of left sub-array
    int n2 = R - mid; /// size of right sub-array

    int tmpL[n1];
    int tmpR[n2];

    /// fill up
    for(int i=0;i<n1;i++)
    {
        tmpL[i] = arr[L + i];
    }
    for(int i=0;i<n2;i++)
    {
        tmpR[i] = arr[mid + 1 + i];
    }
    int i,j,k;
    i = j = 0;
    k = L;

    while(i < n1 && j < n2)
    {
        if(tmpL[i] > tmpR[j])
        {
            arr[k] = tmpR[j];
            inv_cnt += (n1 - i);
            j++;
        }
        else
        {
            arr[k] = tmpL[i];
            i++;
        }
        k++;
    }
    while(i < n1)
    {
        arr[k] = tmpL[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = tmpR[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int L,int R) /// sort a subarray "arr" from L to R
{
    //cout << L << " " << R << endl;
    //getchar();
    if(L<R)
    {
        int mid = (L+R)/2;
        mergeSort(arr,L,mid);
        mergeSort(arr,mid + 1,R);
        //cout << "sorting done from " << L << " to " << mid << " and " << mid + 1 << " " << R << endl;
        //getchar();
        Merge(arr,L,mid,R);
    }
}

int main()
{
    int arr[] = {6,5,4,3,2,1};
    inv_cnt = 0;
    mergeSort(arr,0,5);
    cout << inv_cnt << endl;
    return 0;
}
