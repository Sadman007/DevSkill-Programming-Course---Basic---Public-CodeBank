#include <bits/stdc++.h>
using namespace std;

/// primality testing -> O(sqrt(n))
bool isPrime(long long n)
{
    if(n < 2) return false;
    for(long long i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

/// divisor finding -> O(sqrt(n))
vector<int> findDivisors(int n)
{
    vector<int>divisors; // 2 + 2 + 2 + ... + 1
    for(int i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            divisors.push_back(i);
            if(i != n / i)
                divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

bool isSquare(long long n)
{
    long long sq = sqrtl(n);
    return sq * sq == n;
}

int main()
{
    //cout << isPrime(1000000007);
    //vector<int> dv = findDivisors(36);
    //for(auto it : dv)
    //    cout << it << " ";
    long long n;
    while(cin >> n)
    {
        if(n <= 0) break;
        if(isSquare(n)) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
