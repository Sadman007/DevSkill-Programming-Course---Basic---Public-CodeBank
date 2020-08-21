#include <bits/stdc++.h>
using namespace std;

long long inv_count;
int arr[200000];
int n;

void do_merge(int *arr, int L, int M, int R)
{
	int s1 = M - L + 1; /// size of left sub-array
	int s2 = R - M; /// size of right sub-array

	int left_aux[s1], right_aux[s2];

	for(int i = 0; i < s1; i++)
	{
		left_aux[i] = arr[L + i];
	}
	for(int i = 0; i < s2; i++)
	{
		right_aux[i] = arr[M + 1 + i];
	}

	int i, j, k;
	i = j = 0;
	k = L;

	while(i < s1 && j < s2) /// left and right ACTIVE
	{
		if(left_aux[i] <= right_aux[j])
		{
			arr[k] = left_aux[i];
			i++;
			k++;
		}
		else
		{
			arr[k] = right_aux[j];
			j++;
			k++;
			inv_count = (inv_count + (s1 - i));
		}
	}
	while(i < s1) /// left ACTIVE
	{
		arr[k] = left_aux[i];
		i++;
		k++;
	}
	while(j < s2) /// right ACTIVE
	{
		arr[k] = right_aux[j];
		j++;
		k++;
	}
}

void merge_sort(int *arr, int L, int R)
{
	if(L < R) /// do split
	{
		int M = (L + R) / 2;
		merge_sort(arr, L, M); /// left sub-array
		merge_sort(arr, M + 1, R); /// right sub-array
		do_merge(arr, L, M, R);
	}
}

int main()
{
	inv_count = 0;
	n = 200000;
	for(int i = 0; i < n; i++) arr[i] = n - i;
	merge_sort(arr, 0, n - 1);
	cout << inv_count << "\n";
	return 0;
}
