#include <bits/stdc++.h>
using namespace std;

void setTask()
{
    multiset<string>st;
    st.insert("aaa");
    st.insert("ab");
    st.insert("bcc");
    st.insert("bc");
    st.insert("a");
    st.insert("abc");

    for(auto it : st)
    {
        cout << it << "\n";
    }

}

/**
    Given N integer numbers , find how many triplets are there such that A+B+C = 0

    **BRUTEFORCE**
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(arr[i]+arr[j]+arr[k] == 0)
                    cnt++;
            }
        }
    }


    **OPTIMIZATION**
    map<int,int>mp;
    int cnt = 0;
    for(int i=0;i<n;i++) /// O(nlogn)
    {
        mp[arr[i]] = 1;
    }

    for(int i=0;i<n;i++) /// O(n^2)
    {
        for(int j=0;j<n;j++)
        {
            int c = arr[i]+arr[j];
            if(mp[-c]==1) cnt++;
        }
    }

**/

void mapTask()
{
    //int freq[100] = {0};
    map<string,string>freq;

    freq.insert(make_pair("devskill","programming"));
    freq.insert({"devskill","programming"});
    freq["devskill"] = "programming";

    map<int,int>arr;
    arr[-10] = 5;
}


void priorityQueueTask()
{
    priority_queue<string,vector<string> , greater<string> >pq;
    pq.push("Shubho");
    pq.push("Shahriar");
    pq.push("Nusrat");
    pq.push("Mostafa");
    pq.push("Sakib");
    pq.push("Tariqul");
    pq.push("200");

    while(!pq.empty())
    {
        cout << pq.top() << "\n";
        pq.pop();
    }

}

int main()
{
    priorityQueueTask();
    return 0;
}
