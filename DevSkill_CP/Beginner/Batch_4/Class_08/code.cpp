#include <bits/stdc++.h>
using namespace std;

int getSurfaceArea(int &a, int &b, int &c)
{
    cout << "Before " << a << "\n";
    a++;
    cout << "After " << a << "\n";
    int area = 2*(a*b + b*c + c*a);
    return area;
}

int getVolume(int a, int b, int c)
{
    int vol = a * b * c;
    return vol;
}

void doSomething(int value)
{
    printf("%d\n", value + 5);
    return;
}

void printVector(vector<int>&vc)
{
    for(auto c : vc)
    {
        cout << c << " ";
    }
    cout << "\n";
    return;
}

int main()
{
    /*
    int a, b, c; ///
    cin >> a >> b >> c;
    cout << "Before main " << a << "\n";
    cout << getSurfaceArea(a, b, c) << "\n";
    cout << "After main " << a << "\n";
    */
    vector<int>vc{1, 3, 5};
    printVector(vc);
    //cout << getVolume(a, b, c) << "\n";
    //doSomething(5);
    return 0;
}
