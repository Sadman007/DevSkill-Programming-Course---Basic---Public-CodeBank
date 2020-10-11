#include <bits/stdc++.h>
using namespace std;
#define MAX 10000000
int mb[MAX + 5];

void sieve()
{
	mb[1] = 1;
	for(int i = 1; i <= MAX; i++)
	{
		for(int j = i + i; j <= MAX; j += i)
		{
			mb[j] -= mb[i];
		}
	}
}

int main()
{
	sieve();
	int T;
	scanf("%d", &T);
	while(T--)
	{
		long long N, sum = 0;
		scanf("%lld", &N);
		int LIM = sqrtl(N);
		for(int i = 2; i <= LIM; i++)
		{
			sum -= (N / (1LL * i * i)) * mb[i];
		}
		printf("%lld\n", N - sum);
	}
	return 0;
}