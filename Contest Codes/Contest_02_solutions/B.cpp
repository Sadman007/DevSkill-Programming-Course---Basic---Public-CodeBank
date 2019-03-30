#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int q, c = 1;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        vector<int> arr(n + 1); arr[0] = 0;
        for (int i = 1; i <= n; ++i) cin >> arr[i];

        int mx = 0;
        for (int i = 0; i <= n - 1; ++i) mx = max( mx, arr[i + 1] - arr[i] );

        bool ok = true; int k = mx;
        for (int i = 1; i <= n; ++i) {
            if ( k == arr[i] - arr[i - 1] ) k--;
            else if ( k < arr[i] - arr[i - 1] ) {
                ok = false;
                break;
            }
        }

        cout << "Case " << c << ": ";
        if (ok) cout << mx << endl;
        else cout << mx + 1 << endl;
        c++;
    }

    return 0;
}
