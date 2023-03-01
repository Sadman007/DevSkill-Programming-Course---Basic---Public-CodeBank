#include <bits/stdc++.h>
using namespace std;

mt19937 rd(0);

/// O(N)
int createPartition(vector<int> &arr, int L, int R)
{
    int pvt = arr[R];
    int i = L - 1; /// i = the leftmost position of red zone.
    for (int j = L; j < R; j++)
    {
        if (arr[j] <= pvt) /// color(arr[j]) is red
        {
            swap(arr[i + 1], arr[j]);
            i++;
        }
    }
    /// fix the pivot's position
    swap(arr[i + 1], arr[R]);
    return i + 1;
}

/// Expected O(NlogN)
void quickSort(vector<int> &arr, int L, int R)
{
    if (L >= R) return;
    int p = createPartition(arr, L, R);

    while(p > 0 && arr[p] == arr[p - 1]) --p;
    quickSort(arr, L, p - 1);

    while(p < R && arr[p] == arr[p + 1]) ++p;
    quickSort(arr, p + 1, R);
}

void quickSort(vector<int> &arr)
{
    shuffle(arr.begin(), arr.end(), rd);
    quickSort(arr, 0, arr.size() - 1);
}

int main()
{
    int n = 1000000;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rd());
    }
    quickSort(arr);
    if (is_sorted(arr.begin(), arr.end()))
    {
        cout << "Success!";
    }
    else
    {
        cout << "Failed!";
    }
    return 0;
}
