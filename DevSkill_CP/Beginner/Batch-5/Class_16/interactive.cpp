#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

int main()
{
    int L = 1, R = 100;
    int M;
    while(L < R)
    {
        M = L + (R - L) / 2;
        cout << "Is it greater or equal than " << M << "?\n";
        int status;
        cin >> status;
        if(status == 1)
        {
            L = M + 1;
        }
        else
            R = M - 1;
    }
    cout << "You guessed " << L << "!!!!\n";
    return 0;
}
