#include <bits/stdc++.h>
using namespace std;

int getResult(string &str)
{
    int ans = ((str[0] - '0') - 1) * 10;
    int len = str.size();
    ans += len * (len + 1) / 2;
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        cout << getResult(str) << "\n";
    }
    return 0;
}
