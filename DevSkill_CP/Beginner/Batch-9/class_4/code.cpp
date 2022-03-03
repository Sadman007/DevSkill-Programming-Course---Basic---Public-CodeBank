#include <bits/stdc++.h>
using namespace std;

int get_power(int a, int b) /// O(b)
{
    int res = 1;
    while(b--)
    {
        res *= a;
    }
    return res;
}

void task_to_print_n_times(int n, string message)
{
    for (int i = 1; i <= n; i++)
    {
        cout << message << "\n";
    }
}

void task_to_print_n_by_n_times(int n, string message)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << message << "\n";
        }
    }
}

int main()
{
    /*
    for (int n = 1; n <= 100000000; n++)
    {
        bool is_power_of_two = (n & (n - 1)) == 0;
        if (is_power_of_two == true)
        {
            cout << n << "\n";
        }
    }
    */
    /// for (initialization; conditional_statement; control_statement)
    /*
    int n = 3;
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n && j <= m; j++)
        {

        }
        // task_to_print_n_by_n_times(n, "Hello World!");
    }
    */

    /*
    /// str = "rashid";
    string str = "rashid";
    for (char c = 'a'; c <= 'z'; c++)
    {
        str[2] = c;
        cout << str << "\n";
    }

    */
    int n = 10;
    for (int i = 1; i <= n; i++)
    {
        if (i == 5)
        {
            continue;
        }
        cout << i << "\n";
    }

    return 0;
}
