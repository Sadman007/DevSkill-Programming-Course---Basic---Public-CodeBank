#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

int N;
int board[10][10];

bool isValid(int r,int c)
{
    for(int y = c;y>=0;y--) /// r,c theke baam diker ghor gulo check kore, kono Q ache kina
    {
        if(board[r][y] == 1) return false;
    }
    for(int x = r, y = c; x<N && y>=0;x++,y--) ///  r,c theke south - west diagonal er ghor gulo check kore, kono Q ache kina
    {
        if(board[x][y] == 1) return false;
    }
    for(int x = r, y = c; x>=0 && y>=0;x--,y--) /// r,c theke north - west diagonal er ghor gulo check kore, kono Q ache kina
    {
        if(board[x][y] == 1) return false;
    }
    return true;
}

void backtrack(int col)
{
    if(col == N) /// base case
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                printf("%d ",board[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
        return;
    }

    for(int r=0;r<N;r++)
    {
        if(isValid(r,col))
        {
            board[r][col] = 1; /// backtrack(3)
            backtrack(col + 1); /// backtrack(4)
            board[r][col] = 0; /// backtrack(3)
        }
    }
}

int main()
{
    //cin >> N;
    //backtrack(0);

    int tmp = 5;
    cout << tmp << endl;
    tmp = 0;
    return 0;
}
