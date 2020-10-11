#include <bits/stdc++.h>
using namespace std;

int arr[5];

bool f(int curr, int pos)
{
	if(pos == 5) return curr == 23;
	if(f(curr + arr[pos], pos + 1) ||
	 f(curr * arr[pos], pos + 1) ||
	 f(curr - arr[pos], pos + 1)) return true;
	return false;
}

int main()
{
	while(cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4])
	{
		if( arr[0] == 0 &&
			arr[1] == 0 &&
			arr[2] == 0 &&
			arr[3] == 0 &&
			arr[4] == 0 ) break;

		sort(arr, arr + 5);
		bool isPossible = false;
		do
		{
			if(f(arr[0], 1))
			{
				puts("Possible");
				isPossible = 1;
				break;
			}
		} while(next_permutation(arr, arr + 5));

		if(!isPossible) puts("Impossible");
	}
	return 0;
}
