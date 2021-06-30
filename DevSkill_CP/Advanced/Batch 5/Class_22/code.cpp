#include <bits/stdc++.h>
using namespace std;
struct trieNode
{
    bool isEnd;
    trieNode* next[26];
    trieNode()
    {
       isEnd = false;
       for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};
void Insert(trieNode* root, string &str)
{
    trieNode* currNode = root;
    for(int i = 0; i < (int)str.size(); i++)
    {
        int curr = str[i] - 'a';
        if(currNode->next[curr] == NULL)
            currNode->next[curr] = new trieNode();
        currNode = currNode->next[curr];
    }
    currNode->isEnd = true;
}
bool flag;
void lexicoDfs(trieNode* u, string &str, string &qString)
{
    if(u == NULL) return;
    if(u->isEnd && str != qString)
    {
        flag = false;
        cout << str << "\n";
    }
    for(int i = 0; i < 26; i++)
    {
        if(u->next[i])
        {
            str.push_back(i + 'a');
            lexicoDfs(u->next[i], str, qString);
            str.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    trieNode* root = new trieNode();
    int n, q, cs = 1;
    cin >> n;
    string str;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        Insert(root, str);
    }
    cin >> q;
    while(q--)
    {
        cout << "Case #" << cs++ << ":\n";
        cin >> str;
        trieNode* u = root;
        flag = false;
        string triePref = "";
        for(int i = 0; i < (int)str.size() && !flag; i++)
        {
            if(u->next[str[i] - 'a'])
            {
                triePref.push_back(str[i]);
                u = u->next[str[i] - 'a'];
            }
            else
            {
                flag = true;
            }
        }
        if(flag) cout << "No match.\n";
        else
        {
            flag = true;
            lexicoDfs(u, triePref, str);
            if(flag)
                cout << "No match.\n";
        }
    }
    return 0;
}
