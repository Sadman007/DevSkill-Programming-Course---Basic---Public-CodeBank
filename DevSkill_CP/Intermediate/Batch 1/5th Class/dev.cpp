#include <bits/stdc++.h>
using namespace std;

/**
1 1 4 6 70 70
v = 5

1 1 4 [5] 6 70 70 , lower_bound == upper_bound , jokhon
v array te absent
**/

int arr[1000];
int n,v;

int main()
{
    cout << "Enter the size of the array\n";
    cin >> n;
    for(int i=0;i<n;i++) cin >>arr[i];
    cout << "Enter the value\n";
    cin >> v;


    /// binary search begins
    int st,en,mid;
    st = 0;
    en = n-1;
    /// 1 5 7 12 20 21 21 22 23 23 30
    /// 0 1 2 3  4  5  6   7  8  9 10
    /// v = 23

    /// 0 10
    /// 6 10
    /// 6 8
    /// 6 7
    /// 7 7
    ///
    bool found = false;

    bool fnd = binary_search(arr,arr+n,v);
    cout << fnd << "\n";

    while(st<=en) /// st<=en
    {
        //cout << st << " " << en << "\n";
        mid = (st+en)/2; /// (0+10)/2 = 5
        if(arr[mid]>v) /// arr[mid]!=v
        {
            en = mid-1;
        }
        else if(arr[mid]<v)
        {
            st = mid+1;
        }
        else if(arr[mid]==v)
        {
            found = true;
            cout << "Found " << mid << "\n";
            break;
        }
    }
    /// binary search ends
    /// O(log2(10^5)) = 17 => 25
    cout << found << "\n";
    return 0;
}
