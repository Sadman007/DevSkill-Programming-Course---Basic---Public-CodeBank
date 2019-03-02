#include <bits/stdc++.h>
using namespace std;
int arr[10000];
int N;
/// Selection Sort : Time Complexity O(N^2)
void SelectionSort(int *arr,int N)
{
    /// Selection Sort starts
    for(int i=0;i<N;i++)
    {
        int minIdx = i;
        int minVal = arr[i];
        for(int j=i+1;j<N;j++)
        {
            if(arr[j]<minVal)
            {
                minVal = arr[j];
                minIdx = j;
            }
        }
        swap(arr[i],arr[minIdx]);
    }
    /// Selection Sort ends
}

void InsertionSort(int *arr,int N)
{
    /// O(N^2)
    /// 4 5 1 2 3 5

    /// 1 2 4 5

    for(int i=1;i<N;i++)
    {
        int key = arr[i]; /// key = 2
        int j = i-1; /// j = 1

        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j]; /// arr[j] = arr[1] = 4
            j--;               /// key = 2
        }
        /// j = -1+1 = 0
        arr[j+1] = key;
    }
}

void BubbleSort(int *arr,int N)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

int main()
{
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    ///SelectionSort(arr,N);
    ///InsertionSort(arr,N);
    ///BubbleSort(arr,N)

    /// C++ - Built in Sort - IntroSort
    /// IntroSort = QuickSort + MergeSort + InsertionSort

    /// C - Built in Sort - QuickSort - O(N^2)
    for(int i=0;i<N;i++) cout << arr[i] << " ";
    return 0;
}
