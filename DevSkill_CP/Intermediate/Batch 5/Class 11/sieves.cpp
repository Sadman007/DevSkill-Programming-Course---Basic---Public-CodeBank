#include <bits/stdc++.h>
using namespace std;
#define MAX 10006
#define ll long long

bool isMarked[MAX+5];
int divCnt[MAX+5], sod[MAX+5];
vector<int>divisors[MAX+5];

void sieve(int N) /// roughly O(NloglogN)
{
    isMarked[1] = 1;
    for(int i = 2; i * i <= N; i++) /// O(N)
    {
        if(isMarked[i] == 0)
        {
            for(int j = i * i; j <= N; j += i) /// O(lnN)
            {
                isMarked[j] = 1;
            }
        }
    }
}

void sieve_div(int N) /// O(NlnN)
{
    for(int dv = 1 ; dv <= N; dv++) /// O(N)
    {
        for(int multiple = dv ; multiple <= N; multiple+=dv) /// O(lnN)
        {
            divCnt[multiple]++; /// number of divisors
            divisors[multiple].push_back(dv); /// list of divisors
            sod[multiple]+=dv; /// sum of divisors
        }
    }
}

int main()
{

    return 0;
}

