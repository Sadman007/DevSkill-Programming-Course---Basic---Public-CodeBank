#include <bits/stdc++.h>
using namespace std;


/// s = ")("
/// ]
unordered_map<char, char> mp = {{')', '('}, {']', '['}, {'}', '{'}, {'+', '-'}};
/// mp[')'] = '('
unordered_set<char> opening_bracket({'(', '{', '[', '+'});

bool isValidBracketSeq(string &s) {
    stack<char> stk;
    for (auto c : s)
    {
        if (opening_bracket.count(c))
        {
            stk.push(c);
        }
        else /// c == ')'
        {
            if (!stk.empty() && mp[c] == stk.top())
            {
                stk.pop();
            }
            else return false;
        }
    }
    return stk.empty() == true;
}

int main()
{
    string s;
    cin >> s;
    if (isValidBracketSeq(s)) {
        cout << "Valid!\n";
    }
    else {
        cout << "Invalid!\n";
    }
    main();
    return 0;
}
