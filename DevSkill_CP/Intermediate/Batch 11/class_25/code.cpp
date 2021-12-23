#include <bits/stdc++.h>
using namespace std;

void perm(string &s, int L, int R)
{
    if(L == R)
    {
        cout << s << "\n";
        return;
    }
    for (int i = L; i <= R; i++)
    {
        swap(s[L], s[i]);
        perm(s, L + 1, R);
        swap(s[L], s[i]);
    }
}

int main()
{
    string s = "ABC";
    perm(s, 0, s.size() - 1);
    return 0;
}
