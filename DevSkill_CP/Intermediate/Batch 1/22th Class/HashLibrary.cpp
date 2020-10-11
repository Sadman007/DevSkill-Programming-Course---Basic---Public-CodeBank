#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pr 31
#define type 'a'
#define NUM_OF_HASH 1
#define MAX (int)1e5

ll Hash[NUM_OF_HASH][MAX];
ll power[NUM_OF_HASH][MAX];
ll MOD[] = {1000000007, 1000000009, 998244353, 1000000037,1000000021,1000000003,1000005133};
string str;
int len;

void pre()
{
	for(int i=0;i<NUM_OF_HASH;i++)
	{
	    power[i][0] = 1;
		for(int j=1;j<=len;j++)
		{
			power[i][j] = (power[i][j-1]*pr)%MOD[i];
		}
		Hash[i][0] = str[0]-type+1;
		for(int j=1;j<=len;j++)
		{
			Hash[i][j] = (Hash[i][j-1]*pr + str[j]-type+1)%MOD[i];
		}
	}
	return;
}

ll getHash(int i,int j,int k)
{
    if(!i) return Hash[k][j]%MOD[k];
    return (Hash[k][j]-(Hash[k][i-1]*power[k][j-i+1])+MOD[k]+MOD[k]+MOD[k]+MOD[k]+MOD[k])%MOD[k];
}

int main()
{
	cin >> str;
	len = str.size();
	pre();
        cout << getHash(0,1,0) << " "<<getHash(3,3,0);
	return 0;
}
