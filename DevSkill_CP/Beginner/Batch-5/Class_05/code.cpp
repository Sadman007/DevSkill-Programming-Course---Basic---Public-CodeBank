#include <bits/stdc++.h>
using namespace std;

// O(n)
bool isValid(string bracketSeq)
{
    stack<char>stk;
    for(int i = 0; i < bracketSeq.size(); i++)
    {
        char ch = bracketSeq[i];
        if(ch == ')')
        {
            if(!stk.empty()) stk.pop();
            else return false;
        }
        else if(ch == '(')
            stk.push(ch);
    }
    if(stk.empty()) return true;
    return false;
}

void findPairs(string validSeq)
{
    stack<int>stk;
    for(int i = 0; i < validSeq.size(); i++)
    {
        char ch = validSeq[i];
        if(ch == ')')
        {
            if(!stk.empty())
            {
                cout << stk.top() << " " << i << endl;
                stk.pop();
            }
        }
        else if(ch == '(')
            stk.push(i);
    }
    return;
}

int main()
{
    string bracketSeq;
    cin >> bracketSeq;
    cout << bracketSeq << " --> " << isValid(bracketSeq) << endl;
    findPairs(bracketSeq);
    return 0;
}
