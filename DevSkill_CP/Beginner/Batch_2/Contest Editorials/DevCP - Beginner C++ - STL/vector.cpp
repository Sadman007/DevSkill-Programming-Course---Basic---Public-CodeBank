#include <bits/stdc++.h>
using namespace std;

int main()
{
	int Q;
	scanf("%d", &Q);
	vector<int>vec;
	while(Q--)
	{
		int comp, value, index;
		scanf("%d", &comp);
		if(comp == 0)
		{
			scanf("%d", &value);
			vec.push_back(value);
		}
		else if(comp == 1)
		{
			scanf("%d", &index);
			printf("%d\n", vec[index]);
		}
		else
		{
			if(!vec.empty())
				vec.pop_back();
		}
	}
	return 0;
}