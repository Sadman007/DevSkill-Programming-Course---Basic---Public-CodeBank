#include <bits/stdc++.h>
using namespace std;

unsigned int getCount(unsigned int N)
{
    return N - ((N + 2) / 3);
}

int main()
{
    int T, cs = 1;
    cin >> T;
    while(T--)
    {
        unsigned int P, Q;
        cin >> P >> Q;
        cout << "Case " << cs++ << ": " << getCount(Q) - getCount(P - 1) << "\n";
    }
    return 0;
}
