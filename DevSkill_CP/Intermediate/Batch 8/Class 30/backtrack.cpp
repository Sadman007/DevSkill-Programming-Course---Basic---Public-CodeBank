#include <bits/stdc++.h>
using namespace std;

int grid[10][10];
int N;

bool isSafe(int r, int c)
{
    /// row check
    for(int j = 0; j < c; j++)
    {
        if(grid[r][j] == 1) return false;
    }

    /// diagonal up
    for(int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if(grid[i][j] == 1) return false;
    }

    /// diagonal down
    for(int i = r, j = c; i < N && j >= 0; i++, j--)
    {
        if(grid[i][j] == 1) return false;
    }

    return true;
}

void printGrid()
{
   for(int i = 0; i < N; i++)
   {
       for(int j = 0; j < N; j++)
       {
           printf("%d ", grid[i][j]);
       }
       puts("");
   }
   puts("");
}

void getSolution(int col)
{
    if(col >= N)
    {
       puts("FOUND SOLUTION!");
       printGrid();
       return;
    }
    /// accessing all row elements from col
    for(int i = 0; i < N; i++)
    {
        if(isSafe(i, col))
        {
            grid[i][col] = 1;
            getSolution(col + 1);
            grid[i][col] = 0;
        }
    }
}

void NQueen()
{
    cin >> N;
    memset(grid, 0, sizeof(grid));
    getSolution(0);
}

void getSubset(int pos, vector<int>&sub, vector<int>&vc)
{
    if(pos >= N)
    {
        for(auto it : sub)
            cout << it << " ";
        cout << "\n";
        return;
    }
    getSubset(pos + 1, sub, vc);
    sub.push_back(vc[pos]);
    getSubset(pos + 1, sub, vc);
    sub.pop_back();
}

void SubsetProblem()
{
    vector<int>vc, sub;
    cin >> N;
    vc.resize(N);
    for(int i = 0; i < N; i++)
    {
        cin >> vc[i];
    }
    getSubset(0, sub, vc);
}

int main()
{
    int arr[100];
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    unordered_map<int, int> seen;

    for(int i = 0; i < N; i++)
    {
        if(seen.find(arr[i]) == seen.end())
            cout << arr[i];
        seen[arr[i]] = 1;
    }
    return 0;
}

/// 3 2 5 5 1 2 2 4
