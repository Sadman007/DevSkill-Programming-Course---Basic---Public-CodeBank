#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

/**
    Primality Testing:

        Algo 1)
            for(int i = 2; i < n; i++)
            {
                if(n % i == 0) ---> n is Composite
            }
            ---> n is Prime
**/

/**
    12 = (1,12),(2,6),(3,4)  <--- sqrt(12) = 3
    30 = (1,30),(2,15),(3,10),(5,6) <--- sqrt(30) = 5
    16 = (1,16),(2,8),(4,4) <--- sqrt(16) = 4

     N = a * b
  => N = a * a [farthest divisor of N]
  => N = a^2
  Hence, a = sqrt(N)
**/

bool isPrime(int N) /// TC: O(N)  ---> TC: O(sqrt(N))
{
    if(N < 2) return false;
    /// i <= sqrt(N)
    /// i * i <= N
    for(int i = 2; i * i <= N; i++)
    {
        if(N % i == 0) return false;
    }
    return true;
}

int count_div(int N)
{
    int cnt = 0;
    for(int first_factor = 1; first_factor * first_factor <= N; first_factor++)
    {
        if(N % first_factor == 0)
        {
            cnt++;
            int second_factor = N / first_factor;
            if(second_factor != first_factor) cnt++;
        }
    }
    return cnt;
}

/**
    Use case:
        1) 1000 ta number er primality testing kora lagbe
        2) Scattered distribution
**/

/**
    int mx = 0;
    int num = 0;
    for(int i = 1; i <= 500000; i++)
    {
        int cnt = count_div(i);
        if(mx < cnt)
        {
            mx = cnt;
            num = i;
        }
    }
    cout << mx << " " << num << "\n";

**/
/**
    N = 15 % 8 = 7
        7 % 4 = 3
        3 % 2 = 1
        1 % 1 = 0
    int GCD(int a, int b) /// O(logN); N = max(a,b)
    {
        while(a != 0)
        {
            int new_a = b % a;
            int new_b = a;

            a = new_a;
            b = new_b;
        }
        return b;
    }
    cout << GCD(12, 16) << "\n";
**/
int main()
{
    cout << __gcd(12,16) << "\n";
    return 0;
}
