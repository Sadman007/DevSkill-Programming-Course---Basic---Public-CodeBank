#include <bits/stdc++.h>
using namespace std;

bool isValidParentheses(string &str)
{
    stack<char> stk;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '(')
        {
            stk.push('(');
        }
        else if(str[i] == ')')
        {
            if(stk.empty())
            {
                return false;
            }
            else
            {
                stk.pop();
            }
        }
    }
    if(stk.size() == 0) return true;
    return false;
}

int main()
{
    /// 1 2 3 4 1 5 -> O(N)
    /// 5 1 2 9 0 -1
    /**
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        cout << str << "\n";
    **/

    /**
    vector<int>vc; /// vc = {};
    vc.push_back(5); /// vc = {5};
    vc.push_back(1); /// vc = {5, 1};
    vc.push_back(2); /// vc = {5, 1, 2};
    vc.push_back(9); /// vc = {5, 1, 2, 9};
    vc.push_back(0); /// vc = {5, 1, 2, 9, 0};
    vc.push_back(-1); /// vc = {5, 1, 2, 9, 0, -1};

    sort(vc.begin() + 1, vc.end() - 1); /// IntroSort - hybrid sorting algorithm - (quick,merge/heap,insertion) - O(N*logN)

    for(int i = 0; i < vc.size(); i++)
    {
        cout << vc[i] << " ";
    }
    **/

    string str;
    cin >> str;
    if(isValidParentheses(str)) printf("Valid\n");
    else printf("Invalid\n");
    return 0;
}
