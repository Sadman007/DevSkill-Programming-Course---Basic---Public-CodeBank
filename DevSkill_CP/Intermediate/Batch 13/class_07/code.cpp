#include <bits/stdc++.h>
using namespace std;

map<char, char> mp = {{')', '('}, {']', '['}};
/// {key, value} --> node

bool checkBit(int n, int p)
{
    int exp = 1 << p;
    return (n & exp) == exp;
}

void toggleBit(int &n, int p)
{
    n = n ^ (1 << p);
}

void setBit(int &n, int p)
{
    n = n | (1 << p);
}

int main()
{
    int v = 13;
    toggleBit(v, 2);
    cout << v << "\n";
    return 0;
    //int v = 13;
    for (int i = 7; i >= 0; i--)
    {
        cout << checkBit(v, i);
    }
    return 0;
    set<int> st;
    st.insert(1);
    st.insert(10);
    st.insert(5);
    st.insert(-3);
    st.insert(7); /// st = {-3, 1, 5, 5, 7, 10} -> LB = 2, UB = 4
    auto it = st.lower_bound(2); /// st.lower_bound(), st.upper_bound() // it = 0d10, it = 0d14
    /// int arr[0] , arr[1]
    ///     0d10, 0d14
    /// 26 - 10 = 16 / 4 = 4
    cout << *it;
    return 0;
}
