#include <bits/stdc++.h>
using namespace std;

string open = "({[";
string clos = ")}]";

bool is_balanced(string &str)
{
    stack<char>stk;
    int n = str.size();
    if(n % 2 == 1) return 0;
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

bool is_balanced_adv(string str)
{
    stack<char>stk;
    int n = str.size();
    if(n % 2 == 1) return 0;
    for(int i = 0; i < n; i++)
    {
        ///if(str[i] == '(' || str[i] == '{' || str[i] == '[') /// opening part
        bool open_condition = 0;
        for(int j = 0; j < open.size(); j++)
        {
            if(str[i] == open[j]) open_condition = 1;
        }
        if(open_condition)
        {
            stk.push(str[i]);
        }

        ///else if(str[i] == ')' || str[i] == '}' || str[i] == ']') /// closing part
        bool clos_condition = 0;
        for(int j = 0; j < open.size(); j++)
        {
            if(str[i] == clos[j]) clos_condition = 1;
        }
        if(clos_condition)
        {
            if(stk.empty()) return 0; /// NOT balanced
            else
            {
                ///if(str[i] == ')' && stk.top() == '(') stk.pop();
                ///else if(str[i] == '}' && stk.top() == '{') stk.pop();
                ///else if(str[i] == ']' && stk.top() == '[') stk.pop();
                bool pop_condition = 0;
                for(int j = 0; j < open.size(); j++)
                {
                    if(str[i] == clos[j] && stk.top() == open[j])
                    {
                        stk.pop();
                        break;
                    }
                }
            }
        }
    }
    return stk.empty();
}

int main()
{
    string str;
    cin >> str;
    if(is_balanced(str) == 1)
    {
        cout << "Yes. This string is balanced.\n";
    }
    else cout << "No. This string is NOT balanced.\n";
    cout << str << "\n";
    return 0;
}

