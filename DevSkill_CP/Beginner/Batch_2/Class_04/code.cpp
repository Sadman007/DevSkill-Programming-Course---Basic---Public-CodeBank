#include <bits/stdc++.h>
using namespace std;

int main()
{
    int shomoy;
    cin >> shomoy; /// seconds
    int H, M, S;

    int arr[] = {100,50,20,10,5,2,1};

    for(int i = 0; i < 7; i++)
    {
        cout << shomoy / arr[i] << endl;
        shomoy = shomoy % arr[i];
    }
    cout << endl;

    /**
    H = shomoy / 3600;
    shomoy = shomoy % 3600;

    M = shomoy / 60;
    shomoy = shomoy % 60;

    S = shomoy / 1;
    shomoy = shomoy % 1;

    cout << H << " " << M << " " << S << "\n";
    **/
    return 0;
}
