#include <bits/stdc++.h>
using namespace std;
 
int f(string s, int step)
{
	int new_value = s.size();
	string new_str = to_string(new_value);
	if(new_str == s) return step;
	return f(new_str, step + 1);
}
 
int main()
{
	string str;
	while(cin >> str)
	{
		if(str == "END") break;
		printf("%d\n", f(str, 1));
	}
	return 0;
}