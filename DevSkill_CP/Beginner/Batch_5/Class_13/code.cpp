#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

int lowerbound(vector<int>&arr, int v)
{
    int L = 0;
    int R = arr.size();
    while(L < R)
    {
        int M = L + (R - L) / 2;
        if(arr[M] < v) // 0, 1, 2, 3, 4
            L = M + 1;
        else
            R = M;
    }
    return L;
}

int upperbound(vector<int>&arr, int v)
{
    int L = 0;
    int R = arr.size();
    while(L < R)
    {
        int M = L + (R - L) / 2;
        if(arr[M] <= v) // 0, 1, 2, 3, 4
            L = M + 1;
        else
            R = M;
    }
    return L;
}

int main()
{
    vector<int>arr{1, 2, 2, 6, 6, 6, 8, 10};
    /*
        for(int i = -5; i <= 20; i++)
        {
            cout << i << " : " << upperbound(arr, i) - lowerbound(arr, i) << "\n";
        }
    */
    return 0;
}
