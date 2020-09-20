#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	string s;
	cin>>s>>k;
	long long sum = 0;
	for(char x : s)
	{
		sum += (x-'0');
	}
	sum *= k;
	if(sum % 9 == 0)
		cout<<'9'<<endl;
	else
		cout<< sum%9 <<endl;
	return 0;
}