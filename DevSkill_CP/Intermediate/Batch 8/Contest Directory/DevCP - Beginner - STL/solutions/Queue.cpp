#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<pair<string, int> > Q;
    int N, quant, T;
    string S;
    cin >> N >> quant;
    for(int i = 0; i < N; i++)
    {
        cin >> S >> T;
        Q.push(make_pair(S, T));
    }
    int total = 0;
    while(!Q.empty())
    {
        pair<string, int> cur_process = Q.front();
        Q.pop();
        if(cur_process.second <= quant)
        {
            total += cur_process.second;
            cout << cur_process.first << " " << total << "\n";
        }
        else
        {
            total += quant;
            cur_process.second -= quant;
            Q.push(make_pair(cur_process.first, cur_process.second));
        }
    }

    return 0;
}
