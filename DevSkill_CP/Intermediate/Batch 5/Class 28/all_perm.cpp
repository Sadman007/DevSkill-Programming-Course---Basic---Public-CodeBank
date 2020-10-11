#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

int n;
string str;
unordered_map<string,int>doesExist;

void f(int pvt, int en)
{
    if(pvt == en)
    {
        if(doesExist.find(str) != doesExist.end())
            return;
        cout << str << "\n";
        doesExist[str] = 1;
        return;
    }
    for(int i = pvt; i <= en; i++)
    {
        swap(str[i],str[pvt]);
        f(pvt + 1, en);
        swap(str[i],str[pvt]);
    }
}

int main()
{
    cin >> n;
    cin >> str;
    f(0, n - 1);
    return 0;
}
