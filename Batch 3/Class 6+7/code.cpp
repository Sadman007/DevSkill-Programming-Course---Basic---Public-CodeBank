#include <bits/stdc++.h>
using namespace std;
#define MAX 10010

/**
point2D --> x(int),y(int)
**/

struct point2D
{
    int x,y;
    /// x,y print kora
    void print()
    {
        cout << x << " " << y << endl;
    }
    /// <
    bool operator <(point2D &b)
    {
        if(x == b.x)
        {
            if(y < b.y)
                return true;
            else
                return false;
        }
        else
        {
            if(x < b.x)
                return true;
            else
                return false;
        }
    }
    /// >
    bool operator >(point2D &b)
    {
        if(x == b.x)
        {
            if(y > b.y)
                return true;
            else
                return false;
        }
        else
        {
            if(x > b.x)
                return true;
            else
                return false;
        }
    }
    /// ==
    bool operator ==(point2D &b)
    {
        if(x == b.x && y == b.y) return true;
        return false;
    }
    /// +
    point2D operator +(point2D &b)
    {
        point2D c;
        c.x = x + b.x;
        c.y = y + b.y;
        return c;
    }
};

bool lessThan(point2D a,point2D b)
{
    if(a.x == b.x)
    {
        if(a.y < b.y)
            return true;
        else
            return false;
    }
    else
    {
        if(a.x < b.x)
            return true;
        else
            return false;
    }
}

/**
    point2D a,b;
    1) a < b hobe tokhoni jokhon a.x < b.x hobe,othoba a.x == b.x hole a.y < b.y hobe
**/



int main()
{
    point2D a,b;
    a.x = 5;
    a.y = 6;
    b.x = 1;
    b.y = 2;
    if(a == b) puts("YES");

    point2D arr[10001];
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        arr[i].print();
    }
    return 0;
}
