#include <bits/stdc++.h>
using namespace std;

const int N = 4; /// size of grid
int totalCount;

int grid[N][N];

void printSolution()
{
    totalCount++;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf(" %d ",grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isValid(int row,int col)
{

    /* Check this row on left side */
    for (int i = 0; i < col; i++)
        if (grid[row][i])
            return false;

    /* Check upper diagonal on left side */
    for (int i=row, j=col; i>=0 && j>=0; i--, j--)
        if (grid[i][j])
            return false;

    /* Check lower diagonal on left side */
    for (int i=row, j=col; j>=0 && i<N; i++, j--)
        if (grid[i][j])
            return false;

    return true;
}

void backTrack(int col)
{
    if(col>=N)
    {
        printSolution();
        return;
    }
    for(int i=0;i<N;i++)
    {
        if(isValid(i,col))
        {
            grid[i][col] = 1;
            backTrack(col+1);
            grid[i][col] = 0;
        }
    }
    return;
}

int main()
{
    backTrack(0);
    printf("Total number of solution : %d\n",totalCount);
    return 0;
}
