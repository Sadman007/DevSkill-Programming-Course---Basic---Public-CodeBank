#include <bits/stdc++.h>
using namespace std;

int getSquare(int x)
{
    int result = x * x;
    return result;
}

void countingSort(string& str)
{
    vector<int>freq(26, 0);
    for (int i = 0; i < str.size(); i++) /// O(N)
    {
        int rnk = str[i] - 'a';
        freq[rnk]++;
    }
    int idx = 0;
    for (int i = 0; i < 26; i++) /// O(N + c) -> c = number of missing characters in str in range(a~z)
    {
        int currCount = freq[i];
        while(currCount--)
        {
            str[idx] = 'a' + i; /// 'a' + 0 = 97 + 0 = 97 -> 'a'
            idx++;
        }
    }
}

int main()
{
    /*
    int n;
    cin >> n;
    cout << 125 / n << endl;
    cout << "Hello world" << endl;
    */
    string str = "sakib";
    countingSort(str);
    cout << str;

    return 0;
}
