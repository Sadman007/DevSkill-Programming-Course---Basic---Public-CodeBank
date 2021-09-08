#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

int main()
{
    set<int>st;
    st.insert(3); /// O(logN) -> N = current size of set
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(1);
    st.insert(2);

    st.erase(2); /// O(logN) -> N = current size of set

    for(auto v : st) {
        //cout << v << " ";
    }

    map<string, int>mp;
    mp["sakib"] = 5;
    mp["Akib"] = 10;
    mp["Nazmul"] = 100;

    cout << mp["sakib"] << endl;
    return 0;
}
