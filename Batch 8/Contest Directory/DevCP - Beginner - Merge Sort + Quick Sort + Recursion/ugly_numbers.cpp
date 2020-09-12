#include <bits/stdc++.h>
using namespace std;

vector<long long>ugly;
unordered_map<long long, bool>already_generated;

void gen(long long curr)
{
	if(curr > 1e17) return;
	if(already_generated.find(curr) != already_generated.end()) return;
	already_generated[curr] = 1;
	ugly.push_back(curr);
	gen(curr * 2);
	gen(curr * 3);
	gen(curr * 5);
}

int main()
{
	gen(1LL);
	sort(ugly.begin(), ugly.end());
	printf("The 1500'th ugly number is %lld.\n", ugly[1499]);
	return 0;
}
