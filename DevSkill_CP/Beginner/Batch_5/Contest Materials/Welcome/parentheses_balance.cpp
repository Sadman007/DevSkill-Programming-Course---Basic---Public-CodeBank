#include <bits/stdc++.h>
using namespace std;

bool is_balanced(string &str)
{
    stack<char>stk;
    int n = str.size();
    if(n % 2 == 1) return 0;
    if(n == 0) return 1;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') /// opening part
        {
            stk.push(str[i]);
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']') /// closing part
        {
            if(stk.empty()) return 0; /// NOT balanced
            else
            {
                if(str[i] == ')' && stk.top() == '(') stk.pop();
                else if(str[i] == '}' && stk.top() == '{') stk.pop();
                else if(str[i] == ']' && stk.top() == '[') stk.pop();
            }
        }
    }
    str[0] = 'A';
    return stk.empty();
}

int main()
{
    int T;
    string str;
    cin >> T;
    getchar();
    while(T--)
    {
        getline(cin, str);
        if(is_balanced(str)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
