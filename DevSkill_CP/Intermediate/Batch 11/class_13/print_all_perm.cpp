#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

void print_all_perm(int L, int R, string &s)
{
    if (L == R)
    {
        cout << s << "\n";
        return;
    }
    for (int i = L; i <= R; i++)
    {
        swap(s[L], s[i]);
        print_all_perm(L + 1, R, s);
        swap(s[L], s[i]);
    }
}

int main()
{
    string s = "abc";
    print_all_perm(0, s.size() - 1, s);
    return 0;
}
