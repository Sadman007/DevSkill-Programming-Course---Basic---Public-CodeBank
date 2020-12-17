#include <bits/stdc++.h>
using namespace std;
int N, C, arr[100005];

bool f(int mid)
{
	int cnt = 1;
	int i = 0, j = 1;
	while(j < N)
	{
		if(arr[j] - arr[i] >= mid)
        {
            cnt++;
            i = j;
        }
        j++;
	}
	return cnt >= C;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d",&N, &C);
		int L, R, M;
		L = 1;
		R = INT_MAX / 2;
		for(int i = 0; i < N; i++)
			scanf("%d", &arr[i]);

		sort(arr, arr + N);
		while(L < R)
		{
			M = (R + L + 1) / 2;
			if(f(M)) L = M;
			else R = M - 1;
		}
		printf("%d\n", R);
	}
	return 0;
}
