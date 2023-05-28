#include <bits/stdc++.h>
using namespace std;

mt19937 rng(0);
// O(log2N)
bool exists(vector<int> &vc, int x)
{
    int L = 0, R = vc.size() - 1;
    while(L <= R)
    {
        int M = (L + R) / 2;
        if (vc[M] == x) return true;
        if (vc[M] < x) L = M + 1;
        else R = M - 1;
    }
    return false;
}

int get_random(int L, int R)
{
    return L + (rng() % (R - L + 1));
}

void BINARY_SEARCH_TEST()
{
    /// [-100, 100]
    int n = 100;
    vector<int> vc;
    for (int i = 0; i < n; i++)
    {
        vc.push_back(get_random(-100, 100));
    }
    sort(vc.begin(), vc.end());
    for (auto elem : vc)
    {
        if (!exists(vc, elem))
        {
            puts("DANGER!");
        }
    }
}

int lower_bound_custom(vector<int>&vc, int x)
{
    int L = 0, R = vc.size();
    while(L < R)
    {
        int M = (L + R) / 2;
        if (vc[M] < x) L = M + 1;
        else R = M;
    }
    return L;
}

int upper_bound_custom(vector<int>&vc, int x)
{
    return lower_bound_custom(vc, x + 1);
/*
    int L = 0, R = vc.size();
    while(L < R)
    {
        int M = (L + R) / 2;
        if (vc[M] <= x) L = M + 1;
        else R = M;
    }
    return L;
*/
}

int main()
{
    lower_bound();
    upper_bound();
    return 0;
}
