#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

/// pointer -> call by reference
/// O(N), O(1)
bool isAnagram(string &s1, string &s2)
{
    if(s1.size() != s2.size()) return false;
    vector<int>freq(26, 0);
    for(auto ch : s1)
        freq[ch - 'a']++;
    for(auto ch : s2)
        freq[ch - 'a']--;
    for(int i = 0; i < 26; i++)
        if(freq[i] != 0)
            return false;
    return true;
}

void anagramTest()
{
    string s1 = "abc";
    string s2 = "cbb";
    cout << isAnagram(s1, s2) << endl;
}

int main()
{
    vector<int>indices[26];
    string s = "aabcbad";
    int idx = 0;
    for(auto c : s)
    {
        indices[c - 'a'].push_back(idx);
        idx++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(indices[i].empty()) continue;
        cout << (char)(i + 'a') << " : ";

        for(auto v : indices[i])
            cout << v << " ";

        cout << endl;
    }
}
/**
3
[null]
enter
abc
enter
zzz
enter
qwer
enter

**/
