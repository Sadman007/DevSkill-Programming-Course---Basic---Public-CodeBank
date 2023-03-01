#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
vector<int> tree[4 * MAX + 5];

void merge_child(int L, int R, int nd)
{
    auto &left = tree[nd + nd];
    auto &right = tree[nd + nd + 1];
    int iL = 0;
    int iR = 0;
    while(iL < left.size() &&
            iR < right.size())
    {
        if (left[iL] <= right[iR])
        {
            tree[nd].push_back(left[iL++]);
        }
        else
        {
            tree[nd].push_back(right[iR++]);
        }
    }

    while(iL < left.size())
    {
        tree[nd].push_back(left[iL++]);
    }
    while(iR < right.size())
    {
        tree[nd].push_back(right[iR++]);
    }
}

void build_tree(vector<int> &arr, int L, int R, int nd)
{
    if (L > R) return;
    if (L == R)
    {
        tree[nd].push_back(arr[L]);
        return;
    }
    int M = L + (R - L) / 2;
    build_tree(arr, L, M, nd + nd);
    build_tree(arr, M + 1, R, nd + nd + 1);
    merge_child(L, R, nd);
}

void print_arr(vector<int> &arr)
{
    for (auto &elem : arr)
    {
        cout << elem << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> arr = {10, 9, -1, 4, -3, -2, -5, 25, 14, 3, 9, 12, 24, 18, -5, 0};
    build_tree(arr, 0, arr.size() - 1, 1);
    for (int i = 1; i <= 31; i++)
    {
        cout << "node " << i << " : ";
        print_arr(tree[i]);
    }
    return 0;
}
