#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
vector<int>divisors[MAX + 5];

void div_finding_sieve() /// O(NlogN)
{
    for(int i = 1; i <= MAX; i++)
    {
        for(int j = i; j <= MAX; j += i)
        {
            divisors[j].push_back(i);
        }
    }
}

int expo(int a, int b)
{
    if(b == 0) return 1;
    if(b % 2 == 0)
    {
        int v = expo(a, b / 2);
        return v * v;
    }
    return (a * expo(a, b - 1));
}

int main()
{
    cout << expo(5,3);
    return 0;
}
