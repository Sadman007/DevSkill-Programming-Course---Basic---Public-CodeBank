#include <bits/stdc++.h>
using namespace std;

void VECTOR()
{
    int n;
    cin >> n;
    vector<int> vc(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
    }

    reverse(vc.begin(), vc.end());

    for (auto elem : vc) // foreach() iterator
    {
        cout << elem << " ";
    }

    /**
    for (int i = 0; i < vc.size(); i++)
    {
        auto elem = vc[i];
        cout << elem << " ";
    }
    **/
}

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    set<char> st;
    for (auto c : str)
    {
        st.insert(tolower(c));
    }
    puts(st.size() == 26 ? "YES" : "NO");
    return 0;
}

/**
10
5 1 2 5 1 6 -4 2 3 0
**/
