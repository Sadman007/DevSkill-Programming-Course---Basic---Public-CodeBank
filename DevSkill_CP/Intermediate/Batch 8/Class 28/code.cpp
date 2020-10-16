#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

unsigned int A[10000001];
unsigned int B[10000001];
unsigned int C[10000001];
unsigned int D[10000001];

int n;

int main()
{
    cin >> n;
    D[0] = 1; /// D[i] = D theke D tei ashbo i ta move e
    for(int i = 1; i <= n; i++)
    {
        A[i] = (B[i - 1] + C[i - 1] + D[i - 1]) % MOD;
        B[i] = (A[i - 1] + C[i - 1] + D[i - 1]) % MOD;
        C[i] = (A[i - 1] + B[i - 1] + D[i - 1]) % MOD;
        D[i] = (A[i - 1] + B[i - 1] + C[i - 1]) % MOD;
    }
    cout << D[n] << "\n";
    return 0;
}
