#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

bool taken[10];
int perm[10];
int N;
int arr[10];
map< vector<int>, bool> repeatCheck;

void backtrack(int pos) /// backtrack(0),backtrack(1),backtrack(2)
{
    if(pos == N)
    {
        for(int i=0;i<N;i++) cout << perm[i]+1 << " "; /// 0+1,1+1,2+1
        cout << endl;
        return;
    }
    for(int i=0;i<N;i++)
    {
        /// taken[]={0,0,0};
        /// taken[]={1,0,0};
        /// taken[]={1,1,0};
        if(taken[i] == 0)
        {
            taken[i] = 1; /// taken[]={1,0,0} , taken[]={1,1,0}, taken[]={1,1,1};
            perm[pos] = i; /// perm[0] = 0, perm[1] =1 , perm[2] = 2;
            backtrack(pos+1); /// backtrack(1), backtrack(2)
            taken[i] = 0; /// taken[] = {1,1,0}
        }
    }
}

int main()
{
    N = 4;
    backtrack(0);
    return 0;
}

