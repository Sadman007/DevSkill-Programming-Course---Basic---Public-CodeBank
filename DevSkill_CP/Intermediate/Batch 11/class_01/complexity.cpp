#include <bits/stdc++.h>
using namespace std;

int arr[100000];

void do_sth(int n) /// O(log2(n))
/// 1 << i ----> 2^i
{
    int sum = 0;
    /// n = 1000
    /// i = 10 ---> 2^10 > 1000

    /// 2^k > n
    /// log(2^k) > log(n)
    for(int i = 1; (1 << i) <= n; i++)
    {
        sum += i;
    }
}

void do_sth_2(int n)
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; (1 << j) <= 100; j++)
        {
            sum += i;
        }
    }
}
int main()
{
    cout << sizeof(int) << endl;
    return 0;
}
