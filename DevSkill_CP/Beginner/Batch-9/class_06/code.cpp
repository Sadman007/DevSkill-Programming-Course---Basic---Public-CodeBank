#include <bits/stdc++.h>
using namespace std;
mt19937 rng(0);

/// Time complexity: O(1)
long long get_summation(int n)
{
    long long sum = 1LL * n * (n + 1) / 2;
    return sum;
}

int main()
{
    // freopen("out.txt", "w", stdout);
    /*
    int T = 100000;
    while(T--)
    {
        int n = 100000000;
        cout << get_summation(n) << "\n";
    }*/
    set<int> st;
    for (int i = 1; i <= 1000000; i++)
    {
        st.insert(rng());
    }
    cout << st.size() << "\n";
    return 0;
}
