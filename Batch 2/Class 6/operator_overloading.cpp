#include<bits/stdc++.h>
using namespace std;

struct point2D
{
    int x,y;
    point2D() {}
    point2D(int _x,int _y)
    {
        x = _x; /// 2
        y = _y; /// 3
    }
    point2D operator+(const point2D& q)const
    {
        point2D res;
        res.x = x + q.x;
        res.y = y + q.y;
        return res;
    }
    point2D operator*(const point2D& q)const
    {
        point2D res;
        res.x = x * q.x;
        res.y = y * q.y;
        return res;
    }
};

bool cmpX(point2D p,point2D q)
{
    if(p.x == q.x)
    {
        return p.y<q.y;
    }
    else
    {
        return p.x<q.x;
    }
}

/**
    + add(p,q) ---> (p.x+q.x , p.y+q.y)
    * multiply(p,q) ---> (p.x*q.x , p.y*q.y)
    <  p<q  --->
    {
        if y of p and y of q are equal ===> then we need to check if x of p is less than x of q
            else ===> we need to check if y of p is less than y of q
    }bool cmp(point2D p,point2D q)
{
    if(p.x == q.x)
    {
        return p.y<q.y;
    }
    else
    {
        return p.x<q.x;
    }
}
    >  p>q  ---> p.x > q.x
**/
/**
    function e amra dui vabe value pass korte pari
    1) call by value
    2) call by reference
**/

/// power(a,b) ===> a^b power(5,6) ===> 5^6 = 5*5*5*5*5*5
int power(int a,int b)
{
    int res = 1;
    while(b--)
    {
        res*=a;
    }
    return res;
}


int main()
{
    vector<point2D>vec;

    vec.push_back(point2D(5,11));
    vec.push_back(point2D(1,2)); ///
    vec.push_back(point2D(2,-12)); ///
    vec.push_back(point2D(2,5)); ///
    vec.push_back(point2D(2,3)); ///
    vec.push_back(point2D(50,-11)); ///
    vec.push_back(point2D(50,11));
    vec.push_back(point2D(50,11));

    //sort(vec.begin(),vec.end(),cmpX);
    //sort(vec.begin(),vec.end(),cmpY);
    sort(vec.begin(),vec.end(),cmpX);

    for(int i=0; i<vec.size(); i++)
    {
        printf("(%d,%d)\n",vec[i].x,vec[i].y);
    }

    /**
        (2,-12)
        (50,-11)
        (1,2)
        (2,3)
        (2,5)
        (5,11)
        (50,11)
    **/
    return 0;
}
