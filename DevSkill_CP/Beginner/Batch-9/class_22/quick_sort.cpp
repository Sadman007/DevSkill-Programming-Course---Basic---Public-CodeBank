#include <bits/stdc++.h>
using namespace std;
mt19937 rd(0);
 
int createPartition(vector<int>&arr, int L, int R)
{
  int pvt = arr[R];
  int i = L - 1;
  for(int j = L; j < R; j++)
  {
    if(arr[j] <= pvt)
    {
      swap(arr[++i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[R]);
  return i + 1;
}
 
void quickSort(vector<int>&arr, int L, int R)
{
  if(L < R)
  {
    int p = createPartition(arr, L, R);
    while(p > 0 && arr[p] == arr[p - 1]) --p;
    quickSort(arr, L, p - 1);
    while(p < R && arr[p] == arr[p + 1]) ++p;
    quickSort(arr, p + 1, R);
  }
}
 
bool isValid(vector<int>&vc)
{
  for(int i = 0; i + 1 < vc.size(); i++)
  {
    if(vc[i] > vc[i + 1]) return false;
  }
  return true;
}
 
int main()
{
    vector<int>vc;
    for(int i = 0; i < 100000; i++)
        vc.push_back(100);
    shuffle(vc.begin(), vc.end(), rd);
    quickSort(vc, 0, vc.size() - 1);
    if(isValid(vc)) puts("CORRECT");
    else puts("INCORRECT");
}
