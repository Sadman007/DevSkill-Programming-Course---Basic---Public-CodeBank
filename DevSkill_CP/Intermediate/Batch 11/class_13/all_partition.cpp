#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
#define MOD 9999999900000001
#define M 100

vector<int>current_coins; /// {1, 1, 1}

void print_ara(vector<int> &arr)
{
   for (auto coin : arr)
    {
        cout << coin << " ";
    }
    cout << "\n";
}

set<ll> uhash;

ll generate_hash(vector<int> &vc)
{
    ll res = 1;
    for (auto v : vc)
    {
        res = (res * (M + v)) % MOD;
    }
    return res;
}

void generate_partition(int rem)
{
    if (rem == 0)
    {
        //cout << "Found a solution!\n";
        ll hash_value = generate_hash(current_coins);
        if (uhash.count(hash_value) == 0)
        {
            //print_ara();
            uhash.insert(hash_value);
        }
        return;
    }
    for (int i = 1; i <= rem; i++)
    {
        current_coins.push_back(i);
        //cout << "Currently pushing: " << i << ", remaining value: " << rem - i << ", generate_partition(" << rem << ")\n";
        //cout << "Printing current coins: ";
        //print_ara();
        //getchar();
        generate_partition(rem - i); /// generate_partition(0);
        current_coins.pop_back();
    }
}

/// (n, source, medium, destination)
void tower_of_hanoi(int n, char A, char B, char C)
{
    if (n > 0)
    {
        tower_of_hanoi(n - 1, A, C, B);
        cout << "Move a disk from " << A << " to " << C << "\n";
        tower_of_hanoi(n - 1, B, A, C);
    }
}

set<vector<int>>ust;

void generate_special_array(vector<int> &arr, unordered_set<int> &current, int n)
{
    if (current.size() == n)
    {
        if (ust.count(arr)) return;
        print_ara(arr);
        ust.insert(arr);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (current.count(i) == 0)
        {
            for (int pos = 0; pos < arr.size(); pos++)
            {
                if (arr[pos] == 0 && pos + i + 1 < arr.size() && arr[pos + i + 1] == 0)
                {
                    arr[pos] = arr[pos + i + 1] = i;
                    current.insert(i);
                    generate_special_array(arr, current, n);
                    current.erase(i);
                    arr[pos] = arr[pos + i + 1] = 0;
                }
            }
        }
    }
}

int main()
{
    // generate_partition(25);
    // cout << uhash.size() << "\n";
    // tower_of_hanoi(3, 'A', 'B', 'C');
    int n = 7;
    vector<int> arr(n + n, 0);
    unordered_set<int> current;
    generate_special_array(arr, current, n);
    return 0;
}
