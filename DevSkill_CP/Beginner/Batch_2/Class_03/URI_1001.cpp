#include <bits/stdc++.h>
using namespace std;

int main() {
    double A, B;
    cin >> A >> B;
    double w_avg = ((3.5 * A) + (7.5 * B)) / 11.0;
    cout << setprecision(5) << fixed << "MEDIA = " << w_avg << endl;
    return 0;
}
