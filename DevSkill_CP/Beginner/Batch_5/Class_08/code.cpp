#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define ll long long
#define MAX 100000

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/// vc = {{1, -1}, {100}, {3, 5}, {9}, {10}}

void vec()
{
    vector<vector<int> >vc; /// 5 size diye vc ke initialize kortesi
    vector<int>temp{1,2,3};
    vc.push_back(temp);
    //vc[1] = {1, 2};
    //for(auto it : vc[0])
    //    cout << it << " ";
    /*
    vc[0].push_back(1);
    vc[0].push_back(2);
    vc[0].push_back(3);
    vc[0].push_back(4);
    for(auto it : vc[0])
        cout << it << " ";
        */
}

int printLines(int n)
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        ++cnt;
        cout << "Hello World!\n";
    }
    return cnt;
}

vector<int> generateRandomNumbers(int n)
{
   vector<int>randomNumbers;
   for(int i = 0; i < n; i++)
   {
       randomNumbers.push_back(rng());
   }
   return randomNumbers;
}

int main()
{
    vector<int> randomNumbers;
    randomNumbers = generateRandomNumbers(10);
    for(auto num : randomNumbers)
        cout << num << " ";
    return 0;
}
