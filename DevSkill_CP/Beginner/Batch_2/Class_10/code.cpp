#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;

    st.insert(5);
    st.insert(1);
    st.insert(4);
    st.insert(3);
    st.insert(2);

    int item = 3;
    if(st.find(item) != st.end())
    {
        cout << "FOUND!";
    }
    else cout << "NOT FOUND!";

    return 0;
}
