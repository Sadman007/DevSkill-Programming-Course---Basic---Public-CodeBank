#include <bits/stdc++.h>
using namespace std;

int number_of_divisors[1000000];
int sum_of_divisors[1000000];
vector<int>divisor_list[1000000];

void sieve_all(int N)
{
    for(int i=1; i<=N; i++)
    {
        for(int j=i; j<=N; j+=i)
        {
            number_of_divisors[j]++;
            sum_of_divisors[j]+=i;
            divisor_list[j].push_back(i);
        }
    }
}

int main()
{
    sieve_all(100); /// runs sieve for numbers up to N.

    return 0;
}
