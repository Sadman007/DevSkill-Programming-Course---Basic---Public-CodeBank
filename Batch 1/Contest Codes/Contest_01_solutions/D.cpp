#include<bits/stdc++.h>
using namespace std;
int n,arr[105];

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	for (int i=0; i<n; i++)
    {
        for (int j=1; j<n; j++)
        {
            if (arr[j]<arr[j-1])
            {
                swap(arr[j], arr[j-1]);
                printf("%d %d\n", j, j+1);
            }
        }
	}
	return 0;
}
