#include <bits/stdc++.h>
using namespace std;
#define INF 100000000

struct node
{
	int v,cost;
	node(){}
	node(int _v,int _c)
	{
		v = _v;
		cost = _c;
	}
	bool operator>(const node& b)const
    {
        return cost>b.cost;
    }
    bool operator<(const node& a)const
    {
        return cost<a.cost;
    }
};

priority_queue<node, vector<node> , greater<node> > pq;



int main()
{
	node a,b;

	return 0;
}