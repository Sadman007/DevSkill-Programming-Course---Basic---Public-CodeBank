#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

/// sakib -> sajib, rafi
/// sajib -> bill gates, sakib
/// rafi -> sakib, shamim

/// 0 -> {1, 2}
/// 1 -> {3, 0}
/// 2 -> {0, 4}

Student students[100];

int main()
{
    students[0].friendList.push_back(1);
    students[0].friendList.push_back(2);
    int frdId = students[0].friendList[0];
    return 0;
}
