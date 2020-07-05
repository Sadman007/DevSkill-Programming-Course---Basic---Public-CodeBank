#include <bits/stdc++.h>
using namespace std;
/// + , - , * , / , ^ , &, $
struct point2D
{
    int x, y; /// 5, 10

    bool operator<(point2D &b) /// 15, -6
    {
        /// vacuum zone
        return (x < b.x); /// 5 < 15
    }
    bool operator>(point2D &b) /// 15, -6
    {
        return (x > b.x); /// 5 > 15
    }
    /**
        p3.x = p1.x + p2.x
        p3.y = p1.y + p2.y
    **/
    point2D operator+(point2D &b) /// p3 = p3
    {
        point2D res;
        res.x = x + b.x;
        res.y = y + b.y;
        return res;
    }
    point2D operator-(point2D &b) /// p3 = p1 + p2
    {
        point2D res;
        res.x = x - b.x;
        res.y = y - b.y;
        return res;
    }
};

int main()
{
    point2D p1, p2, p3;
    p1.x = 5;
    p1.y = 10;

    p2.x = 15;
    p2.y = -6;

    //if(p1 < p2) cout << "hahahaha\n"; /// p1 < p2
   // else cout << "nananana\n";
    int N = 300000000;
    for(int i = 0; i < N; i++)
    {
        long long c = 1LL * i * (i + 1);
    }
    cout << c << "\n";
    return 0;
}
