#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;
    set<char>st;
    for(int i = 0; i < n; i++)
        st.insert(tolower(str[i]));
    puts(st.size() == 26 ? "YES" : "NO");
    return 0;
}
