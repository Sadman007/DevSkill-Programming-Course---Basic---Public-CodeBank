#include <bits/stdc++.h>
using namespace std;

/**
    Notes:

    STL -> Standard Template Library

    vector : dynamic array
    pair   : just a pair of two elements
    stack  : LIFO data structure

**/

void dis_vector()
{
    int n;
    cin >> n;

    vector<int> vc;

    for(int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        vc.push_back(value);
    }

    sort(vc.begin(), vc.end()); /// O(n * logn) --> IntroSort - Hybrid Sorting Algorithm

    for(int i = 0; i < vc.size(); i++)
    {
        cout << vc[i] << " ";
    }

}

void dis_pair_vec()
{
    vector<pair<int, int> > points{{4, 0}, {1, 1}, {3, 2}, {0, 3}};
    sort(points.begin(), points.end());
    /// you can add more points if you want!
    int d = 4;
    for(auto &point : points)
    {
        point.first += d;
    }
    for(auto point : points)
    {
        cout << point.first << " " << point.second << "\n";
    }
}

bool cmp(pair<int, int>a, pair<int, int>b)
{
    return a.first + a.second < b.first + b.second;
}

void dis_sort_vec_pair()
{
    /// (0, 0), (5, 1), (10, 4)
    /// (0 + d, 0), (5 + d, 1), (10 + d, 4)

    /// (4, 1, 3, 0)  -> (0, 1, 3, 4)
    /// (0, 1, 2, 3)  -> (3, 1, 2, 0)

    vector<pair<int, int> > points{{0, 4}, {1, 1}, {2, 3}, {3, 0}};
    sort(points.begin(), points.end(), cmp);
    for(auto point : points)
    {
        cout << point.first << " " << point.second << "\n";
    }
}

int main()
{
    stack<char> stk;
    /// Balanced parenthesis "()()())((())"
    string parenthesis = "))(("; /// ((())((())))
    for(int i = 0; i < parenthesis.size(); i++)
    {
        if(parenthesis[i] == ')')
        {
            if(stk.size() > 0)
            {
                stk.pop();
            }
            else
            {
                cout << "NOT BALANCED!\n";
                return 0;
            }
        }
        else
        {
            stk.push('(');
        }
    }
    if(stk.empty()) cout << "BALANCED!";
    else cout << "NOT BALANCED!\n";
    return 0;
}

/// 1 2 3 4
