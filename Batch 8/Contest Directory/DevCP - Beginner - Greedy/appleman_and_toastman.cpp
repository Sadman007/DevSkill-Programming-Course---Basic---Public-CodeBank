#include <bits/stdc++.h>
using namespace std;
#define MAX 300000
int arr[MAX + 5];

int main()
{
	int n;
	long long res = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		res += arr[i];
	}
	sort(arr, arr + n);
	for(int i = 0; i < n; i++)
	{
		res += 1LL * min(n - 1, i + 1) * arr[i];
	}
	printf("%lld\n", res);
	return 0;
}