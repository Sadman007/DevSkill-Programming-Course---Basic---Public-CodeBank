#include <bits/stdc++.h>
using namespace std;

bool isDistinct(int num)
{
    string str = to_string(num);
    sort(str.begin(), str.end());
    for(int i = 0; i + 1 < str.size(); i++)
    {
        if(str[i] == str[i + 1]) return 0;
    }
    return 1;
}

int main()
{
    int year;
    cin >> year;
    for(int i = year + 1; ; i++)
    {
        if(isDistinct(i))
        {
            cout << i << "\n";
            return 0;
        }
    }

    return 0;
}
