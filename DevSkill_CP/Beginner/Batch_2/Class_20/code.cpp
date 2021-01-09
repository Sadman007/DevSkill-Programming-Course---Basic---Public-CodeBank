#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
bool isComposite[MAX + 5];
vector<int>divList[MAX + 5];

void sieve() /// O(NloglogN)
{
    isComposite[1] = 1;
    for(int i = 2; i <= MAX; i++)
    {
        if(isComposite[i] == 0)
        {
            for(long long j = 1LL * i * i; j <= MAX; j += i)
            {
                isComposite[j] = true;
            }
        }
    }
    int cnt = 0;
    for(int i = 2; i <= MAX; i++)
    {
        cnt += isComposite[i] == 0;
    }
    cout << cnt << "\n";
}

void sieveDiv() /// O(NlogN)
{
    for(int i = 1; i <= MAX; i++)
    {
        for(int j = i; j <= MAX; j += i)
        {
            divList[j].push_back(i);
        }
    }
    int mx = 0;
    int numb = 0;
    for(int i = 1; i <= MAX; i++)
    {
        //mx = max(mx, (int)divList[i].size()); /// max(a,b) -> returns the maximum between a and b
        if(mx < divList[i].size())
        {
            mx = divList[i].size();
            numb = i;
        }
    }
    cout << mx << " " << numb; /// mx = 240
}

int main()
{
    sieveDiv();

    return 0;
}
