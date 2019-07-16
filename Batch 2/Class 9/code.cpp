#include <bits/stdc++.h>
using namespace std;

int checkBit(int n,int pos)
{
    return (n&(1<<pos));
}
int alterBit(int n,int pos)
{
    return (n^(1<<pos));
}
int setBit(int n,int pos)
{
    /**
       12 = 11[0]0
       setBit(12,1) ---> 11[1]0 -> 14
    **/
    return (n|(1<<pos));
}
void XOR()
{
    int n,arr[100];
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];

    int xo = 0;
    for(int i=0;i<n;i++) /// O(n*n)
    {
        xo=xo^arr[i];
    }
    cout << xo << "\n";
}

string intToString(int n)
{
    stringstream ss;
    ss << n;
    string str;
    ss >> str;
    return str;
}

int StringToInt(string str)
{
    stringstream ss;
    ss << str;
    int n;
    ss >> n;
    return n;
}

int main()
{
    int n = 11;
    n = ~n;
    cout << n;

    return 0;
}
