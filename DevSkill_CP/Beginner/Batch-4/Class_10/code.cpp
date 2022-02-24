#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int>&vec, int x)
{
    int L = 0;
    int R = vec.size();
    while(L < R)
    {
        int M = L + (R - L) / 2;
        if(vec[M] < x)
            L = M + 1;
        else R = M;
    }
    return L;
}
int upperBound(vector<int>&vec, int x)
{
    int L = 0;
    int R = vec.size();
    while(L < R)
    {
        int M = L + (R - L) / 2;
        if(vec[M] <= x)
            L = M + 1;
        else R = M;
    }
    return L;
}
int main()
{
    /**
        vector<int>vec= {12, 23,23, 23,56,67};
        cout << upperBound(vec, 23);
    **/
    int points[100];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &points[i]);
    }
    return 0;
}
