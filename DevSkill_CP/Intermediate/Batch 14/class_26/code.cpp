#include <bits/stdc++.h>
using namespace std;

void generateSubsets(int pos, vector<int> &arr, vector<int> &subset)
{
    if (pos == arr.size())
    {
        for (auto &elem : subset)
        {
            cout << elem << " ";
        }
        cout << "\n";
        return;
    }
    subset.push_back(arr[pos]);
    generateSubsets(pos + 1, arr, subset);
    subset.pop_back();
    generateSubsets(pos + 1, arr, subset);
}

int main()
{
    vector<int> arr {1, 2, 3};
    vector<int> subset;
    generateSubsets(0, arr, subset);
    return 0;
}
