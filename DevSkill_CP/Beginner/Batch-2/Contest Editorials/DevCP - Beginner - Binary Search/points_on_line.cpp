#include <bits/stdc++.h>
using namespace std;
#define ll long long
int arr[100005];

int main()
{
	int n, d;
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	ll ans = 0;
	for(int i = 0; i < n; i++)
	{
		int R = upper_bound(arr, arr + n, arr[i] + d) - arr;
		R--; // it makes sure that we are taking the last occurence of arr[i]+d into consideration (if exists)
		int L = i;
		int cnt = R - L;
		ans += 1LL * cnt * (cnt - 1) / 2;
	}
	printf("%lld\n", ans);
	return 0;
}