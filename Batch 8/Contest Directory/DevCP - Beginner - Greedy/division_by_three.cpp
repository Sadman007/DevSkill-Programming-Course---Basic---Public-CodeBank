#include <bits/stdc++.h>
using namespace std;

long long f(long long n)
{
  return n - ((n + 2) / 3);
}

int main()
{
  int T, cs = 1;
  long long a, b;
  cin >> T;
  while(T--)
  {
    scanf("%lld %lld",&a, &b);
    printf("Case %d: %lld\n", cs++, f(b) - f(a-1));
  }
}