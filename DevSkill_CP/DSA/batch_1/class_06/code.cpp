#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    stack<int>stk;
    stk.push(1);
    stk.push(3);
    stk.push(2);
    cout << "TOP: " << stk.top() << "\n";
    cout << "SIZE: " << stk.size() << "\n";
    stk.pop();
    cout << "TOP: " << stk.top() << "\n";
    */
    queue<int>que; /// 3 2
    que.push(1);
    que.push(3);
    que.push(2);
    cout << "FRONT: " << que.front() << "\n";
    cout << "SIZE: " << que.size() << "\n";
    que.pop();
    cout << "FRONT: " << que.front() << "\n";
    /**
    1
    3
    3
    **/
    return 0;
}
