#include <bits/stdc++.h>
using namespace std;

int n, arr[100];
vector<int>global_subset;

void f(int pos, int rem)
{
    if(rem < 0) return;
    if(pos >= n)
    {
        if(rem == 0 and global_subset.size() > 0)
        {
            for(auto v : global_subset)
            {
                printf(" %d",v);
            }
            printf("\n");
        }
        return;
    }

    f(pos + 1, rem);

    global_subset.push_back(arr[pos]);
    f(pos,rem - arr[pos]);
    global_subset.pop_back();
}

int main()
{
    unsigned int a = 324583975;
    unsigned int b = 43549654;
    unsigned int c = (a * b);
    cout << c << endl;
    n = 3;
    for(int i = 0; i < n; i++) cin >> arr[i];
    f(0,8);
    return 0;
}
