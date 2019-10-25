#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX (ll)1e18
vector<ll>store, store2;

int main()
{
    for(ll i = 1; i<=1000000 ;i++) /// i ^ 3
    {
        ll v = i*i*i;
        store.push_back(v);
    }
    for(int i=0;i<10;i++) cout << store[i] << endl;
    return 0;
}
