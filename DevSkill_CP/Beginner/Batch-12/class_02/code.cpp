#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C, D;
    if (A > B)
        D = 10;
    else if (A > C)
        D = 12;
    else
        D = 15;

    D = (A > B) ? 10 : (A > C ? 12 : 15);

    return 0;
}
