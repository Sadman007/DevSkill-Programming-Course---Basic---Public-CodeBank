#include <bits/stdc++.h>
using namespace std;
/**
    vector
    set
    map
    queue
    stack
    pair
    priority_queue
**/
/// O(n*n) - Selection , Bubble , Insertion
/// O(n*logn) - Merge Sort , Quick Sort

void VectorDiscussion()
{
vector<int>vc;
    vc.push_back(1);  /// vc = {1}
    vc.push_back(-3);  /// vc = {1,-3}
    vc.push_back(100); /// vc = {1,-3,100}
    vc.push_back(3);
    vc.push_back(6);
    vc.push_back(5);

    sort(vc.begin(),vc.end()); /// IntroSort(Merge,Quick,Insertion)!!! O(nlogn)

    for(int i=0;i<vc.size();i++)
    {
        cout << vc[i] << "\n";
    }
    vector<string>v;
    v.push_back("A");
    v.push_back("Ab");
    v.push_back("Ac");
    v.push_back("Ad");
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        cout << v[i] << "\n";
    }
}

void StackQueue()
{
/// stack , queue
    /// stack functions:
    /**
        1. push(element)
        2. pop()
        3. top()
        4. size()
    **/
    stack<string>stk;
    stk.push("bangla");
    stk.push("english");
    stk.push("math");
    stk.push("physics");
    stk.push("accounting");

    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();

    cout << stk.top() << "\n";
    queue<int>q;
    q.push(1);
    q.push(5);
    q.push(6);
    cout << q.front() << "\n";
    q.pop();
    cout << q.front() << "\n";
}


void Set()
{
    /**
        Given an array, find the number of unique integer elements in the array.
        1<=ARRAY_SIZE<=10^6

        Sample Input
        8
        5 4 9 8 4 5 3 2
        Sample Output
        6
    **/

    set<int>st; /// collection of UNIQUE elements

    int N,value;
    cin >> N;

    for(int i=0;i<N;i++)
    {
        cin >> value;
        st.insert(value);
    }

    for(auto it : st)
    {
        cout << it << " ";
    }
    cout << "\n";

    cout << st.size() << "\n";
}

bool cmp(pair<string,int> a, pair<string,int> b)
{
    return a.second < b.second;
}


void PairVector()
{
    vector< pair<string,int> >var;
    var.push_back(make_pair("A",5));
    var.push_back(make_pair("B",1));
    var.push_back(make_pair("Z",100));

    sort(var.begin(),var.end(),cmp);

    for(int i=0;i<3;i++)
    {
        cout << var[i].first << " " << var[i].second << "\n";
    }

}

int main()
{
    map<int,int>mp;
    mp[5] = 0;
    int exist = mp.find(5)!=mp.end();

    cout << exist;

    return 0;
}



