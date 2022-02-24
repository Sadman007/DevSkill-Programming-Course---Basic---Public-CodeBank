#include <bits/stdc++.h>
using namespace std;

int f(int a, int b)
{
    int cnt = 0;
    while(a > 0)
    {
        a = a / b;
        cnt++;
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        if(b == 1)
        {
            b++;
            int step = 1;
            while(a > 0)
            {
                a = a / b;
                step++;
            }
            cout << step << "\n";
        }
        else
        {
            cout << min(f(a, b), 1 + f(a, b + 1)) << endl;
        }
    }
    return 0;
}
