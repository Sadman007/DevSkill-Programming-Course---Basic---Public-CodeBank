#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int arr[10000005];
mt19937 rng(0);

void bubbleSort(int n) /// 1 2 3 4 5
{
    auto st = high_resolution_clock::now();
    for (int i = 0; i < n; i++) /// i = 4
    {
        for (int j = i + 1; j < n; j++) /// j = 2, 3, 4
        {
            if (arr[i] > arr[j]) /// [1] > [2], [3], [4]
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    auto en = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(en - st);
    cout << duration.count() / 1000.00 << " ms";
}

void InsertionSort(int n)
{
    auto st = high_resolution_clock::now();
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    auto en = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(en - st);
    cout << duration.count() / 1000.00 << " ms";
}

void introSort(int n)
{
    auto st = high_resolution_clock::now();
    sort(arr, arr + n);
    auto en = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(en - st);
    cout << duration.count() / 1000.00 << " ms";
}

int main()
{
    int n = 10000000;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rng(); /// [0 ~ 999]
    }
    ///bubbleSort(n);
    InsertionSort(n);
    return 0;
}
