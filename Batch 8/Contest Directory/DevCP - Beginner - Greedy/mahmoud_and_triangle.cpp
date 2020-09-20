#include <bits/stdc++.h>
using namespace std;
int arr[100010];

int main()
{
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  for(int i = 0; i + 2 < n; i++)
  {
    if(arr[i] + arr[i + 1] > arr[i + 2])
    {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}