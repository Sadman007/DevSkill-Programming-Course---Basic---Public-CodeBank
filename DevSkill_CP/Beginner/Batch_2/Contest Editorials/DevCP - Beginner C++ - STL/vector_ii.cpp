#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, Q;
	scanf("%d%d", &n, &Q);
	vector<int>vec[n];
	while(Q--)
	{
		int comp, value, index;
		scanf("%d", &comp);
		if(comp == 0)
		{
			scanf("%d %d", &index, &value);
			vec[index].push_back(value);
		}
		else if(comp == 1)
		{
			scanf("%d", &index);
			for(int i = 0; i < vec[index].size(); i++)
			{
				if(i > 0) printf(" ");
				printf("%d", vec[index][i]);
			}
			printf("\n");
		}
		else
		{
			scanf("%d", &index);
			vec[index].clear();
		}
	}
	return 0;
}