#include <bits/stdc++.h>
using namespace std;

int result(int n)
{
    int a, b, c, d, temp;
    temp = n;

    a = temp % 10;
    temp = temp / 10;

    b = temp % 10;
    temp = temp / 10;

    c = temp % 10;
    temp = temp / 10;

    d = temp % 10;
    temp = temp / 10;

    if(a == b || a == c || a == d || b == c || b== d || c == d)
    {
        n = n + 1;
        n = result(n);
    }
    else
        return n;
}

int main()
{
    int n, answer;
    cin >> n;
    n = n + 1;
    answer = result(n);
    cout << answer << "\n";
    return 0;
}
