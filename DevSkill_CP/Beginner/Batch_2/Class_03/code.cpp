#include <bits/stdc++.h>
using namespace std;

int main()
{
    /// C style I/O
    /**
        int -> %d
        long long int / long long -> %lld
        float -> %f
        array of characters -> %s
        double -> %lf

        scanf() -> returns the number of variables it accepted
        printf() -> returns the number of characters it printed
    **/
    int num1;

    string str = "Mahbub";

    str.pop_back();

    cin >> num1; /// scanf("%d", &num1);
    //cin >> str;

    cout << num1 << "\n";
    cout << str << "\n";

    return 0;
}
