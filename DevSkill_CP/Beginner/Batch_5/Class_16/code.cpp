#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

struct studentInfo
{
    int roll;
    string name;
    double savings;

    void print()
    {
        cout << roll << " " << name << " " << savings << "\n";
    }
};

studentInfo students[100];

/// 2 4 6 1 3 5

/// 2 < 1 - true
/// 1 < 2 - false
/// 2 4

/// 7 14
/// 111 1110 --> 3 3

bool comp(int a, int b)
{
    return a < b; /// false? a >= b
    /*
    if(a % 2 == 0 && b % 2 == 1) return true;
    if(a % 2 == 1 && b % 2 == 0) return false;
    return a < b;
    */

    /*
    int sa = __builtin_popcount(a);
    int sb = __builtin_popcount(b);
    if(sa == sb) return a < b;
    return sa < sb;
    */
}

bool cmp(studentInfo v1, studentInfo v2)
{
    return v1.roll < v2.roll; // a < b;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> students[i].roll >> students[i].name >> students[i].savings;
    }
    sort(students, students + n, cmp);
    for(int i = 0; i < n; i++)
    {
        students[i].print();
    }
    return 0;
}

/**
4
2 ab 137.50
4 xx 0.00
1 yy 1.00
3 zz 5.01
**/
