#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

/// MAX HEAP ( Another thing: MIN HEAP )
vector<int>tree;

int getParent(int node)
{
    return node / 2;
}

/// TC: O(1)
int getMax()
{
    return tree[1]; /// here, tree[1] is the root node of our binary heap.
}

/// TC: O(logN)
void insertIn(int v)
{
    tree.push_back(v);
    int currIdx = tree.size();
    while(currIdx > 1 && tree[getParent(currIdx)] < tree[currIdx])
    {
        swap(tree[getParent(currIdx)], tree[currIdx]);
        currIdx = getParent(currIdx);
    }
}

/// TC: O(logN)
void popMax()
{
    int sz = tree.size();
    swap(tree[1], tree[sz]);
    --sz;
    int currIdx = 1;
    while(currIdx <= sz)
    {
        /// left check ; 2*currIdx
        if((2*currIdx <= sz) && tree[currIdx] < tree[2 * currIdx])
        {
            swap(tree[currIdx], tree[2 * currIdx]);
            currIdx = 2 * currIdx;
        }
        /// right check ; 2*currIdx + 1
        else if((2*currIdx + 1 <= sz) && tree[currIdx] < tree[(2*currIdx) + 1])
        {
            swap(tree[currIdx], tree[(2 * currIdx) + 1]);
            currIdx = (2 * currIdx) + 1;
        }
        else break;
    }
}

void solveGoogleProblem(long long target)
{
    stack<int>stk;
    while(target > 0)
    {
        stk.push(target % 2);
        target /= 2;
    }
    vector<int>ans;
    while(!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }
    for(int i = 1; i < ans.size(); i++)
    {
        int v = ans[i];
        cout << v;
    }
}

int main()
{
    solveGoogleProblem(12);
    /*
    /// init
    tree.push_back(INT_MAX);

    ///5 1 4 10 -1 0 7 2
    insertIn(5);
    insertIn(1);
    insertIn(4);
    popMax(); // 5 is removed
    insertIn(10);
    popMax(); // 10 is removed
    cout << getMax() << endl;

    /// :) The mightly priority_queue!
    priority_queue<int>PQ;
    */

    return 0;
}
