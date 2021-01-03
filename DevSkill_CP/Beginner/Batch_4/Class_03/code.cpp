#include <bits/stdc++.h>
using namespace std;
/**
    i) input / output stream
    ii) file input / output
    iii) buffer in C++
**/
int main()
{
    /*
        int x = 5;
        bool cond2 = x < 10 && x % 2 == 1;
        if(pow(x, 2) > 0 && cond2) cout << "YAHOO\n";
    */
    /*
        int x = 15;
        x = (x < 10) ? x + 1 : x + 5;
        cout << x << "\n";
    */
    /*
        int T;
        cin >> T;
        while(T--)
        {
            int N;
            cin >> N;
            cout << __builtin_popcount(N) << "\n";
        }
    */
    int n, xr = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        xr = xr ^ val;
    }
    cout << xr << "\n";
    return 0;
}
