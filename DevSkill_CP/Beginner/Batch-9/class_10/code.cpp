#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int L, int R)
{
    if (L >= R) return true;
    return (s[L] == s[R]) && (isPalindrome(s, L + 1, R - 1));
}

void genSubset(vector<int>&arr, vector<int>&subset, int currPos)
{
    if (currPos == arr.size())
    {
        for (auto it : subset)
        {
            cout << it << " ";
        }
        cout << "\n";
        return;
    }
    genSubset(arr, subset, currPos + 1);
    subset.push_back(arr[currPos]);
    genSubset(arr, subset, currPos + 1);
    subset.pop_back();
}

unordered_set<long long>magicNumbers;
void genMagicNumber(long long n = 1)
{
    if (n > 1000) return;
    if (magicNumbers.count(n) > 0) return;
    magicNumbers.insert(n);
    genMagicNumber(n * 2);
    genMagicNumber(n * 3);
    genMagicNumber(n * 5);
}

int main()
{
    //string s = "";
    //cout << isPalindrome(s, 0, (int)s.size() - 1) << "\n";
    //vector<int> subset;
    //vector<int> arr = {1, 2, 5, 11, 14};
    //genSubset(arr, subset, 0);
    genMagicNumber();
    int K = 1500;
    vector<long long> mNumbers(magicNumbers.begin(), magicNumbers.end());
    sort(mNumbers.begin(), mNumbers.end());
    cout << mNumbers[K - 1] << "\n";
    return 0;
}
