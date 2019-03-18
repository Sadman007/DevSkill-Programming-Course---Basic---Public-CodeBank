#include <bits/stdc++.h>
using namespace std;

struct student
{
    string name;
    int accurate,velocity,stupidity;
};

bool cmp(student a, student b)
{
    if(a.accurate==b.accurate)
    {
        if(a.velocity==b.velocity)
        {
            if(a.stupidity==b.stupidity)
            {
                return a.name < b.name;
            }
            else
                return a.stupidity < b.stupidity;
        }
        else
            return a.velocity > b.velocity;
    }
    else
        return a.accurate > b.accurate;
}

int main()
{
    int n;
    scanf("%d",&n);
    student a[n];

    for(int i=0; i<n; i++)
    {
        cin >> a[i].name >> a[i].accurate >> a[i].velocity >> a[i].stupidity;
    }

    sort(a,a+n,cmp);

    for(int i=0; i<n; i++)
    {
        cout << a[i].name << endl;
    }

    return 0;
}
