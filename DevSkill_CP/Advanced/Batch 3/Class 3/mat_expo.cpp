#include <bits/stdc++.h>

#define MOD 10
#define clr(ar) memset(ar, 0, sizeof(ar))

using namespace std;

struct Matrix
{
    int row, col;
    int ar[32][32]; /// Change matrix size here, also change to long long for safety

    Matrix() {} ///Beware if matrix can contain negative numbers in matrix exponentiation problems
    Matrix(int n, int m, int diagonal = 0)
    {
        clr(ar);
        row = n, col = m;
        for (int i = min(n, m) - 1; i >= 0; i--)
            ar[i][i] = diagonal;
    }

    /// To multiply two matrices A and B, the number of columns in A must equal the number of rows in B
    Matrix operator* (const Matrix& other) const  /// hash = 709758
    {
        int i, j, k;
        Matrix res(row, other.col);
        long long x, y = (long long)MOD * MOD;

        for(i = 0; i < row; i++)
        {
            for(j = 0; j < other.col; j++)
            {
                for(k = 0, x = 0; k < col; k++)
                {
                    x += ((long long)ar[i][k] * other.ar[k][j]); /// replace matrix other with its transpose matrix to reduce cache miss
                    if (x >= y)
                        x -= y;
                }
                res.ar[i][j] = x % MOD;
            }
        }
        return res;
    }

    /// To add two matrices A and B, the number of columns and rows in A must equal the number of columns and rows in B
    Matrix operator+ (const Matrix& other) const
    {
        Matrix res(row, col);
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                res.ar[i][j] = (ar[i][j] + other.ar[i][j]) % MOD;
            }
        }
        return res;
    }

    Matrix operator^ (long long n) const
    {
        Matrix x = *this, res = Matrix(row, col, 1);
        while (n)
        {
            if (n & 1)
                res = res * x;
            n = n >> 1, x = x * x;
        }
        return res;
    }

    /// Transpose matrix, T[i][j] = ar[j][i]
    Matrix transpose()
    {
        Matrix res = Matrix(col, row);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.ar[j][i] = ar[i][j];
            }
        }
        return res;
    }

    /// rotates the matrix 90 degrees clockwise
    Matrix rotate()
    {
        Matrix res = this->transpose();
        for (int i = 0; i < res.row; i++)
            reverse(res.ar[i], res.ar[i] + res.col);
        return res;
    }

    inline void print()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("%d%c", ar[i][j], ((j + 1) == col) ? 10 : 32);
            }
        }
    }
};
