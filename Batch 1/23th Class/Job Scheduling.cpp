#include <bits/stdc++.h>
using namespace std;

struct info
{
    int deadline,profit;
    info(){}
    bool operator<(const info &a)const
    {
        if(deadline == a.deadline) return profit>a.profit;
        return deadline<a.deadline;
    }
};
info task[1010];

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> task[i].deadline >> task[i].profit;
    }
    sort(task,task+n);
    int total_profit = task[0].profit;
    int cur_deadline = task[0].deadline;

    int idx = 1;

    while(idx<n)
    {
        if(task[idx].deadline==cur_deadline)
        {
            idx++;
            continue;
        }
        total_profit+=task[idx].profit;
        cur_deadline = task[idx++].deadline;
    }
    cout << "Max Profit is " << total_profit << "\n";

    return 0;
}
