#include <bits/stdc++.h>
using namespace std;

int a1[100000];
long long a2[100000];
double a3[50000];
int x, y, z;

bool cmp(int a, int b) /// O(N) ; a < b
{
    int da = 0, db = 0;
    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0) da++;
    }
    for (int i = 1; i <= b; i++)
    {
        if (b % i == 0) db++;
    }
    if (da < db) return true;
    else if (da == db)
    {
        return (a < b);
    }
    else return false;
}

int main()
{
    /// a1 = 4 * 10^-1 MB = 0.4 MB
    /// a2 = 8 * 10^-1 MB = 0.8 MB
    /// a3 = 0.5 * 8 * 10^-1 MB = 0.4 MB
    /// STL = Standard Template Library
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(1);
    vec.push_back(12);
    vec.push_back(13);
    vec.push_back(15);
    vec.push_back(6);
    vec.push_back(20);
    sort(vec.begin(), vec.end(), cmp); /// ascending -> IntroSort(Hybrid) -> O(NlogN * K) -> Comparison based sorting algorithm
    /// K = time required to compare two elements.
    /// K = 1
    // reverse(vec.begin(), vec.end()); /// O(N)
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}
