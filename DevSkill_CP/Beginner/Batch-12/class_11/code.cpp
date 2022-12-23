#include <bits/stdc++.h>
using namespace std;

class Point3D
{
    int x, y, z;
};

int main()
{
    set<int> st;
    st.insert(1);
    st.insert(-2);
    st.insert(-4);
    st.insert(3);
    st.insert(5);
    st.insert(100);
    /// -4, -2, [1, 3, 5, 100]
    printf("%d\n", *st.upper_bound(0));

    map<Point3D, vector<int>> mp;
    return 0;
}
