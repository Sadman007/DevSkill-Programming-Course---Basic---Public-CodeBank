#include <bits/stdc++.h>
using namespace std;

/**
STL:
    0. string
    1. vector

        vector<int>vec, vec2;

        vec.push_back(5);
        vec.push_back(10);

        vec2.push_back(1);
        vec2.push_back(2);

        for(int i = 0; i < vec2.size(); i++)
        {
            vec.push_back(vec2[i]);
        }

        for(int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }

    2. set
    3. map
**/
/// 5 3 4 5 6 5 6 => 3 4 5 5 5 6 6 => 3 4 5 6
int main()
{
    set<int> st; /// {-3,1,5} O(log2(N)) /// N = 10^6 log2(N) = 19.8
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.insert(val);
    }
    cout << st.size() << "\n";
    return 0;
}
