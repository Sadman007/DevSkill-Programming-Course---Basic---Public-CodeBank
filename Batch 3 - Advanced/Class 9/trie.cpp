#include <bits/stdc++.h>
using namespace std;

struct trieNode
{
    bool isEnd;
    trieNode* child[26];
    trieNode()
    {
        isEnd = 0;
        for(int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};

void Insert(trieNode* root, string &str)
{
    trieNode* curr = root;
    for(int i = 0; i < (int)str.size(); i++)
    {
        int ch = str[i] - 'a'; /// current character of string
        if(curr -> child[ch] == NULL) /// curr theke 'ch' borabor kono rasta ache kina, NULL maane rasta nai
        {
            curr -> child[ch] = new trieNode(); /// rasta create kortesi
        }
        /// ei scope mean kore je rasta create kora hoye gese / aage thekei rasta ase
        curr = curr -> child[ch]; ///
    }
    curr -> isEnd = true;
}

bool Search(trieNode* root, string &str)
{
    trieNode* curr = root;
    for(int i = 0; i < (int)str.size(); i++)
    {
        int ch = str[i] - 'a';
        if(curr -> child[ch] == NULL)
        {
            return false;
        }
        curr = curr -> child[ch];
    }
    return curr && curr -> isEnd;
}

string str;

void dfs(trieNode* root)
{
    if(root && root->isEnd) cout << str << "\n";
    if(root == NULL) return;
    for(int i = 0; i < 26; i++)
    {
        if(root -> child[i])
        {
            str.push_back(i + 'a');
            dfs(root -> child[i]);
            str.pop_back();
        }
    }
}

int main()
{
    trieNode* root = new trieNode();
    string str = "alice";
    Insert(root, str);
    str = "bob";
    Insert(root, str);
    str = "all";
    Insert(root, str);

    str = "boss";
    Insert(root, str);

    str = "bossy";
    Insert(root, str);

    str = "";
    dfs(root);

    return 0;
}
