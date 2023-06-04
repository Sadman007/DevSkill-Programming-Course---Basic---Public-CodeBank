#include <bits/stdc++.h>
using namespace std;

bool is_set(int value, int pos)
{
    return (value & (1 << pos)) > 0;
}

void set_bit(int &value, int pos)
{
    value = value | (1 << pos);
}

int main()
{
    int v = 13;
    set_bit(v, 5);
    cout << v << "\n";
    /*
    for (int i = 7; i >= 0; i--)
    {
        cout << is_set(v, i);
    }
    */
    return 0;
}
