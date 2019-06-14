#include <bits/stdc++.h>
using namespace std;

int arr[100010];

int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
    }
    sort(arr+1,arr+n+1);

    int mid = (n+1)/2;

    cout << arr[mid] << endl;
    return 0;
}
