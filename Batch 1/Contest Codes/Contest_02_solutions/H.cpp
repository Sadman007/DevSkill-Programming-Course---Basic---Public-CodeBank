#include<bits/stdc++.h>
using namespace std;
int main()
{
    double ab,ac,bc,n,i,r,x,c,R;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ab>>ac>>bc>>r;
        c=r/(r+1);
        R=sqrt(c)*ab;
        cout<<"Case "<<i<<": "<<std::setprecision(10)<<R<<endl;
    }
    return 0;
}

