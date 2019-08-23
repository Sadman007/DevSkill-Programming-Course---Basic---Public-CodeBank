#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int COUNT;

void Merge(int arr[],int L,int mid,int R)
{
    int n1 = mid-L+1; /// left subarray er size
    int n2 = R-mid; /// right subarray er size

    int tmpL[n1] , tmpR[n2];

    /// copy data to temp arrays
    for(int i=0;i<n1;i++)
    {
        tmpL[i] = arr[L+i];
    }

    for(int i=0;i<n2;i++)
    {
        tmpR[i] = arr[mid+1+i];
    }

    int i,j,k;
    i = j = 0;
    k = L;

    /// jotokhon porjonto 2 ta pointer ee jibito
    while(i<n1 && j<n2)
    {
        if(tmpL[i]<=tmpR[j])
        {
            arr[k] = tmpL[i];
            i++;
        }
        else
        {
            arr[k] = tmpR[j];
            ///COUNT+=(n1-i);
            j++;
        }
        k++;
    }

    /// left subarray khali kora
    while(i<n1)
    {
        arr[k] = tmpL[i];
        i++;
        k++;
    }

    /// right subarray khali kora
    while(j<n2)
    {
        arr[k] = tmpR[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[],int L,int R) /// sort a subarray "arr" from index L to R inclusive.
{
    if(L<R)
    {
        int mid = (L+R)/2;
        mergeSort(arr,L,mid);
        mergeSort(arr,mid+1,R);
        Merge(arr,L,mid,R);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];

    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++) cout << arr[i] << " "; puts("");

    return 0;
}
