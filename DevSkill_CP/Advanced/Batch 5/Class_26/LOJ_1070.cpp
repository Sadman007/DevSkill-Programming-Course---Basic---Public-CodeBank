#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
#define mat_int unsigned ll

class matrix
{
public:
    int dimR, dimC;
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
                    sum += (mat[i][k] * oth.mat[k][j]);
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
    cin >> t;
    while(t--)
    {
        ll p, q, n;
        cin >> p >> q >> n;
        matrix ma(2, 2), mb(2, 1);
        ma.mat[0][0] = p;
        ma.mat[0][1] = -q;
        ma.mat[1][0] = 1;
        ma.mat[1][1] = 0;

        mb.mat[0][0] = p;
        mb.mat[1][0] = 2;

        matrix mc = (ma ^ (n - 1)) * mb;
        cout << "Case " << cs++ << ": " << mc.mat[0][0] << "\n";
        //printf("Case %d: %llu\n",cs++, mc.mat[0][0]);
    }
    return 0;
}
