#include <bits/stdc++.h>
using namespace std;

int n;
bool grid[100][100];

void print_state(int x = -1, int y = -1)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == x && j == y)
            {
                printf("(T)");
            }
            else if (grid[i][j]) printf(" Q ");
            else printf(" . ");
        }
        puts("");
    }
    for (int i = 0; i < 3*n; i++) printf("-");;
    puts("");
}

bool no_collision(int r, int c)
{
    /// row-wise
    for (int j = c; j >= 0; j--)
    {
        if (grid[r][j]) return false;
    }
    /// upper corner
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (grid[i][j]) return false;
    }
    /// lower corner
    for (int i = r, j = c; i < n && j >= 0; i++, j--)
    {
        if (grid[i][j]) return false;
    }
    return true;
}

void find_n_queen_states(int col)
{
    /// base case
    if (col >= n)
    {
        print_state();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        //print_state(i, col);
        //getchar();
        if (grid[i][col] == false && no_collision(i, col))
        {
            grid[i][col] = true;
            find_n_queen_states(col + 1);
            grid[i][col] = false;
        }
    }
}

int main()
{
    cin >> n;
    //getchar();
    find_n_queen_states(0);
    return 0;
}
