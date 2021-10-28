#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

void tower_of_hanoi(int n, char A, char B, char C)
{
    if (n > 0)
    {
        tower_of_hanoi(n - 1, A, C, B);
        cout << "Move " << n << " from " << A << " to " << C << "\n";
        tower_of_hanoi(n - 1, B, A, C);
    }
}

int main()
{
    tower_of_hanoi(3, 'A', 'B', 'C');
    return 0;
}
