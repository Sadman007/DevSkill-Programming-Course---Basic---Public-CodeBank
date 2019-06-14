#include <bits/stdc++.h>
using namespace std;

int kolshiLimit[1000];

int main()
{
    int n,w;
    cin >> n >> w;
    for(int i=0;i<n;i++)
    {
        cin >> kolshiLimit[i];
    }
    sort(kolshiLimit,kolshiLimit+n);
    int cnt = 0;
    int sum = 0;

    for(int i=0;i<n;i++)
    {
        sum+=kolshiLimit[i];
        if(sum>w) break;
        cnt++;
    }

    cout << "Kolshi count " << cnt << "\n";

    return 0;
}
