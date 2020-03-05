#include <bits/stdc++.h>
using namespace std;
int n,arr[10];
vector<int>global_storage;

void f(int pos, bool isTaken)
{
    if(pos == n)
    {
        for(auto v : global_storage)
        {
            printf(" %d", v);
        }
        printf("\n");
        return;
    }

    f(pos + 1, 0);

    global_storage.push_back(arr[pos]);
    f(pos + 1, 1);
    global_storage.pop_back();
}

int main()
{
    n = 3;
    for(int i = 0; i < n; i++) cin >> arr[i];
    f(0,0);
    return 0;
}

