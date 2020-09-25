#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int pr[MAX + 5];

int get_parent(int x)
{
	if(x == pr[x]) return x;
	return pr[x] = get_parent(pr[x]);
}

void connect(int a, int b)
{
	int pa = get_parent(a);
	int pb = get_parent(b);
	pr[pa] = pb;
}

// find cycle in an undirected graph
void solve_find_cycle()
{
	int n, m, u, v;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		pr[i] = i;
	bool cycle = 0;
	for(int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		int pu = get_parent(u);
		int pv = get_parent(v);
		if(pu == pv)
			cycle = 1;
		connect(pu, pv);
	}
	if(cycle) puts("CYCLE");
	else puts("NO CYCLE");
}



int main()
{
	solve_find_cycle();
	return 0;
}