#include <bits/stdc++.h>
using namespace std;

bool findValue(vector<int> &vec, int T)
{
    int L = 0;
    int R = vec.size() - 1;
    while(L <= R)
    {
        int M = (L + R) / 2;
        if(vec[M] < T)
        {
            L = M + 1;
        }
        else if(vec[M] == T)
        {
            return true;
        }
        else /// vec[M] > T
        {
            R = M - 1;
        }
    }
    return false;
}

int main()
{
    vector<int>vec{1, 3, 5, 8, 10, 15, 110, 282};
    for(int target = 1; target <= 10; target++)
    {
        cout << target << " : " << findValue(vec, target) << "\n";
    }

    return 0;
}
