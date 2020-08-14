#include <bits/stdc++.h>
using namespace std;

int divCnt[1010];
vector<int> vc;

bool cmp(int a, int b)
{
	if(divCnt[a] == divCnt[b]) return a> b;
	return divCnt[a] < divCnt[b];
}

int main() {
	// div count sieve
	for(int i = 1; i <= 1000; i++)
	{
		for(int j = i; j <= 1000; j += i)
		{
			divCnt[j]++;
		}
	}
	for(int i = 1; i <= 1000; i++) vc.push_back(i);
	sort(vc.begin(), vc.end(), cmp);
	// preprocessing done
	
	int T, cs = 1;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		printf("Case %d: %d\n", cs++, vc[n - 1]);
	}
	return 0;
}