#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MAX_DIM 2

ll MOD = 10000000;

struct matrix
{
    ll r, c, data[MAX_DIM][MAX_DIM];
    matrix()
    {
        r = c = 1;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                data[i][j] = 0;
            }
        }
    }
    matrix(int _r, int _c)
    {
        r = _r;
        c = _c;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                data[i][j] = 0;
            }
        }
    }
    void identity()
    {
        if(r != c) return;
        for(int i = 0; i < r; i++)
        {
            data[i][i] = 1;
        }
    }
    matrix operator*(const matrix &b)const
    {
        matrix answer(r, b.c);
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < b.c; j++)
            {
                answer.data[i][j] = 0;
                for(int k = 0; k < c; k++)
                {
                    answer.data[i][j] = (answer.data[i][j] + (data[i][k] * b.data[k][j]));
                    while(answer.data[i][j] < 0) answer.data[i][j] += MOD;
                    if(answer.data[i][j] >= MOD) answer.data[i][j] %= MOD;
                }
            }
        }
        return answer;
    }

    matrix operator^(ll expo)
    {
        matrix res;
        res.identity();
        matrix x(r,c);
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                x.data[i][j] = data[i][j];
            }
        }
        while(expo > 0)
        {
            if(expo & 1) res = res * x;
            expo = expo >> 1;
            x = x * x;
        }
        return res;
    }

    void print()
    {
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                printf("%d ",data[i][j]);
            }
            puts("");
        }
        puts("");
    }
};



int main()
{
    //freopen("out.txt", "w", stdout);
    ll n, m;
    while(scanf("%lld %lld",&n, &m) == 2)
    {
        if(n < 2)
        {
            printf("%lld\n", n % (1 << m));
            continue;
        }
        ll res = 0;
        MOD = 1LL << m;
        matrix a(2,2);
        a.data[0][0] = a.data[0][1] = a.data[1][0] = 1;
        matrix b(2,1);
        b.data[0][0] = 1;
        matrix c = a ^ (n - 1);
        c = c * b;
        printf("%lld\n", c.data[0][0]);
    }
    return 0;
}
