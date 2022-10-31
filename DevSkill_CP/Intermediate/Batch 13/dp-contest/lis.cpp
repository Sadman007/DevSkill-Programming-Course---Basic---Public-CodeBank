#include <bits/stdc++.h>
using namespace std;
int arr[100010];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    vector<int>seq;
    for(int i = 0; i < n; i++)
    {
        int pos = lower_bound(seq.begin(), seq.end(), arr[i]) - seq.begin();
        if(pos == seq.size()) seq.push_back(arr[i]);
        else seq[pos] = arr[i];
    }
    printf("%d\n", seq.size());
    return 0;
}
