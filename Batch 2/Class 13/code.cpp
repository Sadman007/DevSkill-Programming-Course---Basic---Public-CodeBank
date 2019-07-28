#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define BASE 26
#define ll long long

string str;
int len;
ll power[100000];
ll H[100000];

void pre()
{
    power[0] = 1; /// 10^0 = 1
    for(int i=1;i<len;i++)
    {
        power[i] = (power[i-1]*BASE)%MOD;
    }
    H[0] = str[0]-'0';
    for(int i=1;i<len;i++)
    {
        H[i] = (H[i-1]*BASE + (str[i]-'0'))%MOD;
    }
    return;
}

ll getHash(int L,int R)
{
    return (H[R]-(H[L-1]*power[R-L+1])+MOD)%MOD;
}

ll generateHash(string s)
{
    ll HashValue = 0;
    for(int i=0;i<(int)s.size();i++)
    {
        HashValue = (HashValue*BASE + (s[i]-'0'))%MOD;
    }
    return HashValue;
}

int main()
{
    cin >> str;
    len = str.size();
    pre();
    cin >> s2;

    ll H2 = generateHash(s2);

    for(int i=0;i<len;i++)
    {
        if(getHash(i,i+s2.size()-1) == H2)
        {
            cout << "substring found at " << i << "\n";
        }
    }


    return 0;
}
