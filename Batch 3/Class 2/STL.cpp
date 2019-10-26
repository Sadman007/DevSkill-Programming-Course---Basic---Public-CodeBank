#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int>stk)
{
    stack<int>tmp;
    tmp = stk;
    while(!tmp.empty())
    {
        cout << tmp.top() << " ";
        tmp.pop();
    }
}

void test_stack()
{
    stack<int>stk;

    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    ///cout << stk.top() << endl;

    stk.pop(); /// 1 2 3 4
    stk.pop(); /// 1 2 3
    stk.push(134); /// 1 2 3 134
    stk.pop(); /// 1 2 3
    stk.push(222); /// 1 2 3 222

    ///cout << stk.top() << endl;
    printStack(stk);
    while(stk.empty() == 0) /// stk.empty() ---> true , jokhon stack ta khali. Otherwise, false
    {
        stk.pop();
    }
}

struct point2D
{
    double x,y;
};

void test_queue()
{
    queue<point2D>Q;

    Q.push({-1,2});
    Q.push({10,2});
    Q.push({10.5,2});
    Q.push({999,2});

    point2D temp = Q.front();
    cout << temp.x << "\n";
    cout << temp.y << "\n";
    //Q.pop();
    //cout << Q.front() << endl;
}

void test_PQ()
{
    /*
    srand(time(0));

    priority_queue<int>PQ;
    int N, arr[N];
    N = 10000000;

    for(int i = 0; i < N ; i++)   /// O(N*log2(N))
    {
        cin >> arr[i]; /// 1 ta kaaj
        PQ.push(arr[i]); /// O(log2(N))
    }
    */
}

void test_vector()
{
    vector<int>arr;
    for(int i=0;i<10;i++)
    {
        arr.push_back(rand());
    }
    sort(arr.begin(), arr.end()); /// O(NlogN) - IntroSort = (Quick + Heap + Insertion)
    for(int i=0;i<10;i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    set<int>st;

    st.insert(1);
    st.insert(13453);
    st.insert(14523);
    st.insert(1);
    st.insert(15);
    st.insert(13493);
    st.insert(134);
    st.insert(134);

    for(auto item : st)
    {
        cout << item << " ";
    }

    return 0;
}
