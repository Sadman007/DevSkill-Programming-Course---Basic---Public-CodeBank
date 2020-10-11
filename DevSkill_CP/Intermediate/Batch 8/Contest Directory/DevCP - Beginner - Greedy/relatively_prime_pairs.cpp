#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long L, R;
	scanf("%lld %lld", &L, &R);
	puts("YES");
	for(long long i = L; i <= R; i += 2)
	{
		printf("%lld %lld\n", i, i + 1);
	}
	return 0;
}