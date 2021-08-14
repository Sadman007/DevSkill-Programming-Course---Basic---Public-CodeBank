#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

struct Point {
    ll x, y;
    Point(){}
    Point(ll a, ll b) {
        x = a;
        y = b;
    }
    bool operator<(Point &p) {
        return x < p.x || (x == p.x && y < p.y);
    }
    void print() {
        cout << x << " " << y << endl;
    }
};

// Cross product of two vectors OA and OB
// returns positive for counter clockwise
// turn and negative for clockwise turn
ll cross_product(Point &O, Point &A, Point &B) {
    return (A.x - O.x) * (B.y - O.y)
           - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> points) {
    int n = points.size(), k = 0;
    if(n < 4) return points;
    vector<Point> hull(2 * n);

    // Sort points lexicographically.
    sort(points.begin(), points.end());

    // Build lower hull.
    for(int i = 0; i < n; i++) {
        // If the point at K-1 position is not a part
        // of hull as vector from ans[k-2] to ans[k-1]
        // and ans[k-2] to A[i] has a clockwise turn
        while(k >= 2 && cross_product(hull[k - 2], hull[k - 1], points[i]) <= 0)
            k--;
        hull[k++] = points[i];
    }
    // Build upper hull.
    for(int i = n - 1, t = k + 1; i > 0; i--) {
        // If the point at K-1 position is not a part
        // of hull as vector from ans[k-2] to ans[k-1]
        // and ans[k-2] to A[i] has a clockwise turn
        while(k >= t && cross_product(hull[k - 2], hull[k - 1], points[i - 1]) <= 0)
            k--;
        hull[k++] = points[i - 1];
    }
    hull.resize(k - 1);
    return hull;
}

int main()
{
    auto hull = convex_hull({{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}});
    for(auto it : hull)
        it.print();
    return 0;
}
