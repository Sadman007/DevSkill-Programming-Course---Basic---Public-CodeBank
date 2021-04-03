#include <bits/stdc++.h>
using namespace std;

/*
int f(int n);
int g(int n);

int f(int n)
{
    if(n < 0) return 0;
    if(n == 0) return 3;
    return 5 * f(n - 1) + 2 * g(n - 2);
}

int g(int n)
{
    if(n < 0) return 0;
    if(n == 0) return 2;
    return 3 * g(n - 3) + f(n - 1);
}
*/
int n, target, arr[100];
vector<int>subset;

void f(int curr, int sum)
{
    if(curr == n)
    {
        if(sum == target)
        {
            printf("{");
            for(auto elem : subset)
            {
                cout << elem << ",";
            }
            cout << "}\n";
        }
        return;
    }
    subset.push_back(arr[curr]);
    f(curr + 1, sum + arr[curr]);
    subset.pop_back();

    f(curr + 1, sum);
    return;
}

int main()
{
    cin >> n >> target;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    f(0, 0);
    return 0;
}
