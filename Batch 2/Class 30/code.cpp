#include <bits/stdc++.h>
using namespace std;

/**
    Binary Search:
        * lower_bound / upper_bound

    * Problem 1 *
        L theke R porjonto koyta prime number ache. Jekhane L,R deya thakbe.
        1<=L<=R<=10^6
        1<=Q<=10^5
    * Solution 1 *
        O(Q*logN) : N = N / ln(N)
**/

int main()
{
    int n, L, R, arr[100];
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];

    cin >> L >> R;

    int lo = lower_bound(arr,arr+n,L)-arr; /// O(logN) : N = array size
    int up = upper_bound(arr,arr+n,R)-arr; /// O(logN) : N = array size

    ///cout << "lower bound of " << v << " is " << lo << " " << up << endl;;
    cout << "tot count " << up-lo << endl;
    return 0;
}
