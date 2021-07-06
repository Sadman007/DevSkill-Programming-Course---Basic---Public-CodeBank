#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

int main()
{
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        string str(n, 'a');
        for(int i = n - 2; i >= 0; i--) {
            if(k <= (n - i - 1)) {
                str[i] = 'b';
                str[n - k] = 'b';
                break;
            }
            k -= n - i - 1;
        }
        cout << str << "\n";
    }
    return 0;
}
