#include <bits/stdc++.h>
using namespace std;

int main()
{
    /// Q - ("p1", 50) , ("p2", 150) , .....
    int n, q, processTime;
    string processName;
    queue< pair<string, int> > Q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        cin >> processName >> processTime;
        Q.push(make_pair(processName, processTime));
    }

    int T = 0;
    while(!Q.empty())
    {
        auto frontProcess = Q.front();
        Q.pop();
        if(frontProcess.second <= q)
        {
            T += frontProcess.second;
            cout << frontProcess.first << " " << T << "\n";
        }
        else
        {
            T += q;
            frontProcess.second -= q;
            Q.push(frontProcess);
        }
    }
    return 0;
}
