#include <bits/stdc++.h>
using namespace std;

string str;

void permute(int l,int r)
{
    if(l==r)
        cout << "result : " << str << "\n\n";
    else
    {
        for(int i=l; i<=r; i++)
        {
            swap(str[l],str[i]);
            permute(l+1,r);
            swap(str[l],str[i]);
        }
    }
}

int main()
{
    str = "abc";
    permute(0,str.size()-1);
    return 0;
}
