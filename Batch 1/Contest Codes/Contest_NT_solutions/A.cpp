#include <bits/stdc++.h>
using namespace std;
vector<int>prm;
bool isP[1020];

void sieve()
{
    memset(isP,0,sizeof isP);
    for(int i=2;i*i<=1010;i++)
    {
        if(isP[i]==0)
        {
            for(int j=i+i;j<=1010;j+=i)
            {
                isP[j] = 1;
            }
        }
    }
    for(int i=2;i<=1010;i++)
    {
        if(isP[i]==0) prm.push_back(i);
    }
}

int main()
{
    sieve();
	int n,k,cnt=0;
	scanf("%d%d",&n,&k);

	for(int i=0;i<prm.size();i++)
    {
        if(prm[i]+prm[i+1]+1 <= n and !isP[prm[i]+prm[i+1]+1])
            cnt++;
    }

	if(cnt>=k) puts("YES");
	else puts("NO");
	return 0;
}
