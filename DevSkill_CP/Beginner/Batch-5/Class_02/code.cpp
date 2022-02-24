#include <bits/stdc++.h>
using namespace std;


int main()
{
    /**
        short int -> 2 Byte -> 16 bit -> [-2^15 ~ 2^15 - 1] -> [-32768, 32767]
    **/
    int a = 1 << 300;
    cout << a << endl;
    short int var;
    var = 100000000000LL;
    int d;
    while(cin >> d)
    {
        var += d;
        cout << "new value : " << var << endl;
    }
    return 0;
}
