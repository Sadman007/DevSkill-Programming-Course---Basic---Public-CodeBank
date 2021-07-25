#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
#define mat_int int

int po[5] = {1, 10, 100, 1000, 10000};

class matrix
{
public:
    int dimR, dimC, MOD = (int)1e4;
    vector<vector<mat_int> > mat;
    matrix(int _dimR, int _dimC)
    {
        dimR = _dimR;
        dimC = _dimC;
        mat.clear();
        mat.resize(dimR, vector<mat_int>(dimC, 0));
        if(dimR == dimC)
        {
            for(int i = 0; i < dimR; i++)
                mat[i][i] = 1;
        }
    }
    matrix operator*(const matrix& oth)
    {
        int nr = dimR;
        int nc = oth.dimC;
        matrix newMat(nr, nc);
        for(int i = 0; i < nr; i++)
        {
            for(int j = 0; j < nc; j++)
            {
                mat_int sum = 0;
                for(int k = 0; k < dimC; k++)
                {
                    sum += (mat[i][k] * oth.mat[k][j]) % MOD;
                    sum %= MOD;
                }
                newMat.mat[i][j] = sum;
            }
        }
        return newMat;
    }
    matrix operator^(ll p)
    {
        matrix res(dimR, dimC);
        matrix x = *this;
        while(p > 0)
        {
            if(p % 2 == 1)
                res = x * res;
            p /= 2;
            x = x * x;
        }
        return res;
    }
    void print()
    {
        cout << "......\n";
        for(int i = 0; i < dimR; i++)
        {
            for(int j = 0; j < dimC; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "......\n";
    }
};

int main()
{
    int t, cs = 1;
    scanf("%d", &t);
    while(t--)
    {
        int a, b, n, m;
        scanf("%d %d %d %d", &a, &b, &n, &m);
        matrix ma(2, 2), mb(2, 1);
        ma.mat[0][1] = 1;
        ma.mat[0][0] = 1;
        ma.mat[1][0] = 1;
        ma.mat[1][1] = 0;

        mb.mat[0][0] = b;
        mb.mat[1][0] = a;

        matrix mc = (ma ^ (n - 1)) * mb;
        printf("Case %d: %d\n",cs++, mc.mat[0][0] % po[m]);
    }
    return 0;
}
