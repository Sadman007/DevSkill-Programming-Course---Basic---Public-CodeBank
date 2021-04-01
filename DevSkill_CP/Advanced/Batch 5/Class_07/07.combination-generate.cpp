#include <bits/stdc++.h>

using namespace std;

bool chkbit(int mask, int p) { return mask & (1 << p); }

int n = 4;
string fr[] = {"abcd", "pqrs", "uvwx", "xyz"};

int main() {
    for(int mask=0; mask<(1<<n); mask++) {
        cout << mask << " : ";
        for(int i=0; i<n; i++) {
            if(chkbit(mask, i)) cout << fr[i] << " ";
        }
        cout << endl;
    }


}
