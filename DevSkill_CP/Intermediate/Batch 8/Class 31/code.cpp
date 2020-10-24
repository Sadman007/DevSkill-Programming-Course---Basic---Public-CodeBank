#include <bits/stdc++.h>
using namespace std;

string str;

void perm(int L, int R)
{
    if(L == R)
    {
        cout << str << "\n";
        return;
    }
    for(int i = L; i <= R; i++)
    {
        swap(str[i], str[L]);
        perm(L + 1, R);
        swap(str[i], str[L]);
    }
}

int main()
{
    str = "abc";
    perm(0, str.size() - 1);
    return 0;
}
