#include <bits/stdc++.h>
using namespace std;

bool checkBit(int num, int pos)
{
	int res = num & (1 << pos);
	return (res > 0);
}

bool binarySearch(vector<int>&arr, int target)
{
    int L = 0;
    int R = arr.size() - 1;
    while(L <= R)
    {
        int M = (L + R) / 2;
        if(arr[M] == target) return true;
        if(arr[M] > target) R = M - 1;
        else L = M + 1;
    }
    return false;
}

int main()
{
    vector<int>vc{1,3,5,234,786,234,87789,2325,432,-1};
    sort(vc.begin(), vc.end());
    for(int i = -1000; i <= 1000; i++)
    {
        if(binarySearch(vc, i))
        {
            cout << i << " ";
        }
    }
    return 0;
}
