#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int>PQ;
    char str[10];
    int val;

    while(scanf("%s", str) != EOF)
    {
        if(strlen(str) == 3) break;
        if(str[0] == 'i')
        {
            scanf("%d", &val);
            PQ.push(val);
        }
        else
        {
            printf("%d\n", PQ.top());
            PQ.pop();
        }
    }
    return 0;
}

