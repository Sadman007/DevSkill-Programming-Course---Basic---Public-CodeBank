#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pr 31
#define MAX 100000
#define MOD 1000000007

ll Hash[MAX+5];
ll power[MAX+5];

string str;
int len;

void pre()
{
	power[0] = 1;
	for(int i=1;i<=MAX;i++) power[i] = (power[i-1]*pr)%MOD;
	Hash[0] = str[0]-'a';
	for(int i=1;i<len;i++)
	{
		Hash[i] = (Hash[i-1]*pr + str[i]-'a')%MOD;
	}
	return;
}

ll getHash(int i,int j)
{
    return (Hash[j]-(Hash[i-1]*power[j-i+1])+MOD)%MOD;
}

int main()
{
	cin >> str;
	len = str.size();
	pre();

    cout << getHash(0,0) << " "<<getHash(1,1);
	return 0;
}
