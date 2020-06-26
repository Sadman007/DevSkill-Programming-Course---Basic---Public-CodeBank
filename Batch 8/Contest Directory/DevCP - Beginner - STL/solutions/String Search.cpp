#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
char sS[MAX + 5], tS[MAX + 5];

int main()
{
    string S,T;
    scanf("%s %s",sS, tS);

    S = sS;
    T = tS;

    int szT = T.size();
    int szS = S.size();

    for(int i = 0; i < szS; i++)
    {
        string kata_string = S.substr(i,szT);
        if(kata_string == T)
        {
            printf("%d\n",i);
        }
    }

    return 0;
}
