#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int p = 1e3 + 5;
vector<int>primes[p+10];
int dis[p+10],visit[p+10];

void seive()
{
    for(int i=2; i<=p; i++)
    {
        if(primes[i].size()==0)
        {
            for(int j=i; j<=p; j+=i)
            {
                primes[j].push_back(i);
            }
        }
    }
}

int bfs(int a,int b)
{
    for(int i=1; i<=p; i++)
    {
        visit[i]=0;
    }

    queue<int>q;
    q.push(a);
    dis[a]=0;
    visit[a]=1;

    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x==b)
        {
            return dis[x];
        }
        for(int child : primes[x])
        {
            int next = x + child;
            if(next<p && visit[next]==0)
            {
                q.push(next);
                visit[next]=1;
                dis[next]=dis[x]+1;
            }
        }
    }
    if(!visit[b]) return -1;
    return dis[b];
}

int main()
{
    seive();
    int T,a,b;
    cin>>T;
    for(int i=1; i<=T; i++)
    {
        cin>>a>>b;
        cout<<"Case "<<i<<": "<<bfs(a,b)<<endl;
    }
    return 0;
}
