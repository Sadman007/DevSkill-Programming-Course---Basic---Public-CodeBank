#include <bits/stdc++.h>
using namespace std;

int main(){
    int q, i, x;
    scanf("%d", &q);
    set <int> thisSet;
    while(q--)
    {
        scanf("%d %d", &i, &x);
        if(i == 0)
        {
            thisSet.insert(x);
            printf("%d\n", thisSet.size());
        }
        else if(i == 1)
        {
            if(thisSet.find(x) != thisSet.end())
                printf("1\n");
            else
                printf("0\n");
        }
        else
        {
        	thisSet.erase(x);
        }
    }
    return 0;
}