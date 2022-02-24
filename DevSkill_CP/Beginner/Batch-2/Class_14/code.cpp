#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>&vc)
{
    int n = vc.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(vc[i] > vc[j])
                swap(vc[i], vc[j]);
        }
    }
}

int main()
{
    sakib
    vector<int>vc{5,2,6,8,1,2};

    bubble_sort(vc);

    for(auto item : vc)
    {
        cout << item << " ";
    }
    return 0;
}
