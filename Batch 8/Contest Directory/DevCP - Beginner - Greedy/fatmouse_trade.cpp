#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
#define pii pair<int, int>

vector<pii>things;

bool cmp(pii &a, pii &b)
{
	return a.first * b.second > a.second * b.first;
}

int main()
{
	int tot, n, J, F;
	while(1)
	{
		scanf("%d %d", &tot, &n);
		if(tot == -1 && n == -1) break;
		things.clear();
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d", &J, &F);
			things.push_back({J, F});
		}
		sort(things.begin(), things.end(), cmp);
		double rem = tot;
		double res = 0.0;
		for(int i = 0; i < n; i++)
		{
			if(things[i].second <= rem)
			{
				res += things[i].first;
				rem -= things[i].second;
			}
			else
			{
				res += ((1.00 * things[i].first) / things[i].second) * rem;
				break; 
			}
		}
		printf("%0.3f\n", res);
	}
	
	return 0;
}