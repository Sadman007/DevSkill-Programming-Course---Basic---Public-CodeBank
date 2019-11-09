#include <bits/stdc++.h>
using namespace std;

int arr[100], n;

bool doesExist(int v)
{
    int L = 0;
    int R = n-1;
    int M;

    while(L <= R)
    {
        M = (L + R) / 2;
        if(arr[M] > v) R = M - 1;
        else if(arr[M] < v) L = M + 1;
        else if(arr[M] == v) return true;
    }

    return false;
}

double SQRT(double N)
{
    double L = 0.0;
    double R = N;
    double M;
    int cnt = 70;

    while(cnt--)
    {
        M = (L+R)/2;
        if(M*M > N) R = M;
        else L = M;
    }

    return M;
}

int main()
{
    /**
        cin >> n;
        for(int i = 0;i<n;i++) cin >> arr[i];
        sort(arr,arr+n);
        int v;
        cin >> v;
        cout << doesExist(v) << endl;
    **/
    cout << setprecision(10) << fixed << SQRT(1) << endl;
    return 0;
}
