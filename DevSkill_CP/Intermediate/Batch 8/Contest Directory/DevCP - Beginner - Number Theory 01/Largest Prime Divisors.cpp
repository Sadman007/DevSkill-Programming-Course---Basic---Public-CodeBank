#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 10000005
bool isP[MAX+5];
vector<ll>prm;

void sieve()
{
	isP[1] = 1;
	isP[2] = 0;
	for(int i=4;i<=MAX;i+=2) isP[i] = 1;
	for(ll i=3;i*i<=MAX;i+=2) 
	{
		if(!isP[i])
		{
			for(ll j=i*i;j<=MAX;j+=i) isP[j] = 1;
		}
	}
	prm.push_back(2);
	for(int i=3;i<=MAX;i+=2) 
	{
		if(isP[i] == 0)
		{
			prm.push_back(i);
		}
	}
}

ll gen(ll num)
{
	vector<ll>prm_div;
	for(int i=0;i<(int)prm.size() && 1LL*prm[i]*prm[i]<=num;i++)
	{
		if(num % prm[i] == 0)
		{
			while(num % prm[i]==0) num/=prm[i];
			prm_div.push_back(prm[i]);
		}
	}
	if(num>1) prm_div.push_back(num);
	if(prm_div.size() == 1) return -1;
	ll mx = -1;
	for(auto it : prm_div) mx = max(mx,it);
	return mx;
}

int main()
{
	sieve();
	ll num;
	while(scanf("%lld", &num) == 1)
	{
		num = num > 0 ? num : (-1) * num;
		if(num == 0) break;
		else printf("%lld\n",gen(num));
	}
}