#include <bits/stdc++.h>
using namespace std;
char grid[10][10];
const int N = 9;
int brows[10], bcols[10], bboxes[10];

void include(int x, int y, int val)
{
    int box_id = 3 * (x / 3) + (y / 3);
    grid[x][y] = val + '0';
    brows[x] |= 1 << val;
    bcols[y] |= 1 << val;
    bboxes[box_id] |= 1 << val;
}

void exclude(int x, int y, int val)
{
    int box_id = 3 * (x / 3) + (y / 3);
    grid[x][y] = '0';
    brows[x] ^= 1 << val;
    bcols[y] ^= 1 << val;
    bboxes[box_id] ^= 1 << val;
}

bool is_valid(int x, int y, int val)
{
    int box_id = 3 * (x / 3) + (y / 3);
    if ((brows[x] & (1 << val)) > 0) return false;
    if ((bcols[y] & (1 << val)) > 0) return false;
    if ((bboxes[box_id] & (1 << val)) > 0) return false;
    return true;
}

pair<int, int> find_best_move()
{
    int min_score = INT_MAX;
    pair<int, int> mov {-1, -1};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] != '0') continue;
            int curr = 0;
            for (int val = 1; val <= 9; val++)
            {
                if (is_valid(i, j, val))
                    curr++;
            }
            if (curr < min_score)
            {
                min_score = curr;
                mov = {i, j};
            }
        }
    }
    return mov;
}

bool find_solution()
{
    auto mov = find_best_move();
    int x = mov.first;
    int y = mov.second;
    if (x == -1) return true;
    for (int val = 1; val <= 9; val++)
    {
        if (!is_valid(x, y, val)) continue;
        include(x, y, val);
        if (find_solution()) return true;
        exclude(x, y, val);
    }
    return false;
}

void solve_sudoku()
{
    find_solution();
}

int main()
{
    int T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        memset(brows, 0, sizeof brows);
        memset(bcols, 0, sizeof brows);
        memset(bboxes, 0, sizeof brows);
        for (int i = 0; i < N; i++)
        {
            scanf("%s", grid[i]);
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == '.')
                {
                    grid[i][j] = '0';
                }
                else
                {
                    int val = grid[i][j] - '0';
                    include(i, j, val);
                }
            }
        }
        solve_sudoku();
        printf("Case %d:\n", cs++);
        for (int i = 0; i < N; i++)
            printf("%s\n", grid[i]);
    }
    return 0;
}
