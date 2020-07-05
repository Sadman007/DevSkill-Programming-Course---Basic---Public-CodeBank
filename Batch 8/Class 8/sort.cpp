#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int *arr, int n)
{
	for(int i = 1; i < n; i++)
	{
		int j = i;
		while(j >= 1 && arr[j - 1] > arr[j])
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

void CountingSort(int *arr, int n)
{
	int min_value = *min_element(arr, arr + n);
	int max_value = *max_element(arr, arr + n);
	vector<int>freq(max_value + abs(min_value) + 5, 0); /// initialized a vector of specific size (like array) and filled it with zero.

	int OFFSET = 0; /// this is for handling negative values
	if(min_value < 0) OFFSET = abs(min_value);

	for(int i = 0; i < n; i++)
		freq[arr[i] + OFFSET]++;

	int index = 0;
	for(int v = min_value + OFFSET; v <= max_value + OFFSET; v++)
	{
		while(freq[v] > 0)
		{
			arr[index++] = v - OFFSET;
			freq[v]--;
		}
	}
}

int main()
{
	int n = 10;
	int arr[11];
	for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
	for(int i = 0; i < n; i++) cout << arr[i] << " "; cout << "\n";
	CountingSort(arr, n);
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	return 0;
}
