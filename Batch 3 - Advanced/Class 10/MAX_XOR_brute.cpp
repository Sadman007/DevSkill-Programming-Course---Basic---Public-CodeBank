#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

int arr[100];

int main()
{
    int n, mx = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j <n; j++)
        {
            mx = min(mx, arr[i] ^ arr[j]);
        }
    }
    cout << mx << "\n";
    return 0;
}
