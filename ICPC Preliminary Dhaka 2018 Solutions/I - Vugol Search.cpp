#include <bits/stdc++.h>
using namespace std;
#define MAX 200000
#define MOD 202206214218227LL

class TrieNode
{
public:
    int maxScore;
    TrieNode* children[26];
    TrieNode()
    {
        maxScore = 0;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

string sstr;
char str[MAX + 5];
int score[MAX + 5];
unordered_map<long long, TrieNode*> tries;

void insertInTrie(TrieNode* root, string &s, int scr)
{
    TrieNode* curr = root;
    for (auto c : s)
    {
        int id = c - 'a';
        if (curr->children[id] == NULL)
            curr->children[id] = new TrieNode();
        curr = curr->children[id];
    }
    curr->maxScore = scr;
}

void deleteTrie(TrieNode *u)
{
    if (u == NULL) return;
    for (int i = 0; i < 26; i++)
    {
        if (u->children[i])
            deleteTrie(u->children[i]);
    }
    delete(u);
}

void dfs(TrieNode* u)
{
    if (u == NULL) return;
    for (int i = 0; i < 26; i++)
    {
        if(u->children[i])
        {
            dfs(u->children[i]);
            u->maxScore = max(u->maxScore, u->children[i]->maxScore);
        }
    }
}

int getMaximizedScore(TrieNode* root, string &str, bool onlyLCP = false)
{
    TrieNode* curr = root;
    int lcp = 0, maxScore = onlyLCP ? 0 : curr->maxScore;
    for (auto c : str)
    {
        int id = c - 'a';
        if (curr -> children[id] == NULL) break;
        curr = curr -> children[id];
        lcp++;
        maxScore = max(maxScore, lcp + (onlyLCP ? 0 : curr->maxScore));
    }
    return maxScore;
}

long long getHash(string &s)
{
    long long H = 1;
    for (auto c : s)
    {
        H = (H * (c -'a' + 257));
        if (H >= MOD) H%=MOD;
    }
    return H;
}

int main()
{
    // freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, q;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &score[i]);
        }
        TrieNode* root = new TrieNode();
        for (int i = 0; i < n; i++)
        {
            scanf("%s", str);
            sstr = str;
            auto H = getHash(sstr);
            if (tries.count(H) == 0) tries[H] = new TrieNode();
            insertInTrie(tries[H], sstr, score[i]);
            insertInTrie(root, sstr, score[i]);
        }
        for (auto &it : tries)
            dfs(it.second);
        scanf("%d", &q);
        while(q--)
        {
            scanf("%s", str);
            sstr = str;
            auto H = getHash(sstr);
            int s1 = getMaximizedScore(root, sstr, true);
            int s2 = tries.count(H) == 0 ? 0 : getMaximizedScore(tries[H], sstr);
            printf("%d\n", max(s1, s2));
        }
        deleteTrie(root);
        for (auto &it : tries)
            deleteTrie(it.second);
        tries.clear();
    }
    return 0;
}
