#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, t, a, b, da, db, k=0, i, j;
    scanf("%d%d%d%d%d%d", &x, &t, &a, &b, &da, &db);
    for(i=0; i<t; i++)
    {
        for(j=0; j<t; j++)
        {
            if((a-i*da)==x || (b-j*db)==x || (a-i*da+b-j*db)==x || x==0)
            {
                k=1;
                break;
            }
        }
    }
    if(k==1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}