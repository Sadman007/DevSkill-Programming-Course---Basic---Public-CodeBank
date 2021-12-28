#include <bits/stdc++.h>
using namespace std;

void print_string_from_stack(stack<char> &stk)
{
    if (stk.size() == 0) return;
    char elem = stk.top();
    stk.pop();
    print_string_from_stack(stk);
    cout << elem;
}

int main()
{
    string str;
    cin >> str;
    stack<char> stk;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '#')
        {
            if (stk.size() > 0)
                stk.pop();
        }
        else
        {
            stk.push(str[i]);
        }
    }
    // print_string_from_stack(stk);
    string text;
    while (stk.size() > 0)
    {
        text.push_back(stk.top()); /// bikas
        stk.pop();
    }
    reverse(text.begin(), text.end());
    cout << text;
    return 0;
}

// sb#aj#kizx##b
