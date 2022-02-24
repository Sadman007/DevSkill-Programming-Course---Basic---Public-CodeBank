#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

void test1()
{
    unordered_set<int>st;
    st.insert(3);
    st.insert(1);
    st.insert(2);
    st.insert(3);

    for(auto item : st)
    {
        cout << item << " ";
    }
}

int main()
{
    string T, P;
    cin >> T >> P;
    int lenP = P.size();
    int lenT = T.size();
    /// T = abaaa
    /// P = aa
    for(int i = 0; i + lenP <= lenT; i++)
    {
        string sub = T.substr(i, lenP); /// string.substr(starting_index, substring_length)
        if(sub == P)
        {
            cout << i << "\n";
        }
    }
    return 0;
}
