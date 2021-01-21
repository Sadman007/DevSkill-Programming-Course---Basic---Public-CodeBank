#include <bits/stdc++.h>
using namespace std;

long long getRemainder(string &B, long long d)
{
    long long value = 0;
    for(int i = 0; i < B.size(); i++)
    {
        value = (value * 10) + (B[i] - '0');
        value %= d;
    }
    return value;
}

bool isLeap(string &year)
{
    if(getRemainder(year, 4) == 0 && getRemainder(year, 100) != 0)
        return 1;
    if(getRemainder(year, 400) == 0) return 1;
    return 0;
}

bool isHuluculu(string &year)
{
    return getRemainder(year, 15) == 0;
}

bool isBulukulu(string &year)
{
    return getRemainder(year, 55) == 0 && isLeap(year);
}

int main()
{
    //freopen("output.txt","w",stdout);
    string year;
    int cs = 1;
    while(cin >> year)
    {
        if(cs > 1)
        {
            cout << "\n";
        }
        bool ord = 1;
        if(isLeap(year))
        {
            ord = 0;
            cout << "This is leap year.\n";
        }
        if(isHuluculu(year))
        {
            ord = 0;
            cout << "This is huluculu festival year.\n";
        }
        if(isBulukulu(year))
        {
            ord = 0;
            cout << "This is bulukulu festival year.\n";
        }
        if(ord)
        {
            cout << "This is an ordinary year.\n";
        }
        cs++;
    }
    return 0;
}
