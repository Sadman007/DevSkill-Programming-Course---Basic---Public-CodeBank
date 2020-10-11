#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n, t, i, j, up, sum, x;
    cin >> t;
    int k=0;
    while(t--)
    {
        cin >> n;
        vector<int> a;
        for(i=0;i<n;i++) cin >> x, a.push_back(x);
        sort(a.begin(), a.end());
        sum=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
                up=upper_bound(a.begin(), a.end(), a[i]+a[j]-1)-a.begin();
                sum+=(up-j-1);
            }
        }
        cout << "Case " << ++k << ": " << sum << endl;
    }
    return 0;
}
