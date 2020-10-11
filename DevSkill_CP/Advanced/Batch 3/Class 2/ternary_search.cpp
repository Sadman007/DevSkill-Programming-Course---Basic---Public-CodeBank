#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006

struct point3D {
    double x, y, z;
} p[3];

double sq_dist(point3D &a, point3D &b) {
    double d = 0;
    d += (a.x - b.x) * (a.x - b.x);
    d += (a.y - b.y) * (a.y - b.y);
    d += (a.z - b.z) * (a.z - b.z);
    return d;
}

double f() {
    int cnt = 100;
    double d1, d2;

    while(cnt--) {
        point3D m1, m2;

        m1.x = (p[1].x + (2*p[0].x)) / 3.0;
        m1.y = (p[1].y + (2*p[0].y)) / 3.0;
        m1.z = (p[1].z + (2*p[0].z)) / 3.0;

        m2.x = (p[0].x + (2*p[1].x)) / 3.0;
        m2.y = (p[0].y + (2*p[1].y)) / 3.0;
        m2.z = (p[0].z + (2*p[1].z)) / 3.0;

        d1 = sq_dist(m1,p[2]);
        d2 = sq_dist(m2,p[2]);

        if(d1 > d2) p[0] = m1;
        else p[1] = m2;
    }
    return sqrt(sq_dist(p[2],p[1]));
}

int main()
{
    int T, cs = 1;
    scanf("%d", &T);
    while(T--) {
        for(int i = 0; i < 3; i++) scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
        printf("Case %d: %0.10f\n", cs++, f());
    }
    return 0;
}
