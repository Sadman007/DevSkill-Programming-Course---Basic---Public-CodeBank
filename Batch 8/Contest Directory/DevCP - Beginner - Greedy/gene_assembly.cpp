#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct pii
{
  int first, second, idx;
  pii(){}
  pii(int a, int b, int c)
  {
    first = a;
    second = b;
    idx = c;
  }
};

bool cmp(pii &a, pii &b)
{
  if(a.second == b.second)
     return a.first < b.first;
  return a.second < b.second;
}

vector<pii>work;

int main()
{
  int n, L, R;
  while(scanf("%d", &n) == 1)
  {
    if(!n) break;
    work.clear();
    for(int i = 0; i < n; i++)
    {
      scanf("%d %d", &L, &R);
      work.push_back({L, R, i});
    }
    sort(work.begin(), work.end(), cmp);
    vector<int>ans;
    int lastEnd = -1;
    for(int i = 0; i < n; i++)
    {
      if(lastEnd <= work[i].first)
      {
        lastEnd = work[i].second;
        ans.push_back(work[i].idx + 1);
      }
    }
    for(int i = 0; i < ans.size(); i++)
    {
      if(i) printf(" ");
      printf("%d", ans[i]);
    }
    puts("");
  }
}