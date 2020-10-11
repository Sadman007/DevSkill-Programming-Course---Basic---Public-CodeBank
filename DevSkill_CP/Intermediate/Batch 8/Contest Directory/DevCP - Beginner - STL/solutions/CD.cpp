#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, v;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(n == 0 && m == 0) break;
        queue<int>QA,QB;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &v);
            QA.push(v);
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d", &v);
            QB.push(v);
        }
        int cnt = 0;
        while(QA.size() && QB.size())
        {
            if(QA.front() == QB.front())
            {
                cnt++;
                QA.pop();
                QB.pop();
            }
            else if(QA.front() < QB.front())
            {
                QA.pop();
            }
            else QB.pop();
        }
        printf("%d\n", cnt);
    }
    return 0;
}
