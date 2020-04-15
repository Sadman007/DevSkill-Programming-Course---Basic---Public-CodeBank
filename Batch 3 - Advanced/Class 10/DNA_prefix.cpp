#include <bits/stdc++.h>
using namespace std;

struct trieNode
{
    bool isEnd;
    trieNode* child[4];
    int cnt, len;
    trieNode()
    {
        cnt = len = isEnd = 0;
        for(int i = 0; i < 4; i++)
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
        int ch = str[i] - 'A'; /// current character of string
        if(curr -> child[ch] == NULL) /// curr theke 'ch' borabor kono rasta ache kina, NULL maane rasta nai
        {
            curr -> child[ch] = new trieNode(); /// rasta create kortesi
        }
        /// ei scope mean kore je rasta create kora hoye gese / aage thekei rasta ase
        curr = curr -> child[ch]; ///
        curr->cnt++;
        curr->len = i + 1;
    }
    curr -> isEnd = true;
}

void deleteTree(trieNode* root)
{
    for(int i = 0; i < 4; i++)
    {
        if(root->child[i])
        {
            deleteTree(root->child[i]);
        }
    }
    delete root;
}

string str;
long long maxScore;

void dfs(trieNode* root) /// O(X)
{
    if(root == NULL) return;
    maxScore = max(maxScore, 1LL * (root->cnt) * (root->len));
    for(int i = 0; i < 4; i++)
    {
        if(root -> child[i])
        {
            dfs(root -> child[i]);
        }
    }
}

int main()
{
    int T, n, cs = 1;
    cin >> T;
    while(T--) /// 10
    {
        maxScore = 0;
        trieNode *root = new trieNode();
        cin >> n;
        for(int i = 0; i < n; i++) /// O(2.5*10^6)
        {
            cin >> str;
            for(auto &c : str)
            {
                if(c == 'G') c = 'B';
                if(c == 'T') c = 'D';
            }
            Insert(root, str);
        }
        dfs(root); /// O(2.5*10^6)
        cout << "Case " << cs++ << ": ";
        cout << maxScore << "\n";
        deleteTree(root);
    }
    return 0;
}
