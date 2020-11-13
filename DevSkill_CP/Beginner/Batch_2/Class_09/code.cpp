#include <bits/stdc++.h>
using namespace std;

int getFactorial(int n)
{
    int res = 1;
    for(int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}

void greetings(string name)
{
    cout << "Hello " << name << "\n";
}

vector<int> getFactorials(int N)
{
    vector<int>factorials;
    for(int i = 0; i <= N; i++)
    {
        factorials.push_back(getFactorial(i));
    }
    return factorials;
}

int main()
{
    /**
        int n;
        cin >> n; /// n! = 1 * 2 * 3 * ... * n
        cout << getFactorial(n) << "\n";
        string name = "sakib";
        greetings(name);
    **/
    vector<int>res = getFactorials(5);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
