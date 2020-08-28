#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); /// MUST ADD

int do_partition(vector<int>&vc, int L, int R)
{
    int pivot = vc[R];
    int i;
    i = L - 1;
    for(int j = L; j < R; j++)
    {
        if(vc[j] <= pivot)
        {
            i++;
            swap(vc[i], vc[j]);
        }
    }
    swap(vc[i + 1], vc[R]);
    return i + 1;
}

void quick_sort(vector<int>&vc, int L, int R)
{
    if(L < R)
    {
        int pivot_index = do_partition(vc, L, R); /// 5 7 8 9 ---> 1

        quick_sort(vc, L, pivot_index - 1); /// left
        quick_sort(vc, pivot_index + 1, R); /// right
    }
}

int main()
{
    int n;
    n = 1000000;
    vector<int>vc;
    vc.resize(n);

    for(int i = 0; i < n; i++)
        vc[i] = i + 1;

    shuffle(vc.begin(), vc.end(), rng);
    quick_sort(vc, 0, n - 1);

    /**
    int n, sum = 0, trial = 1000;
    cin >> n;

    vector<int>vc(n);

    for(int i = 0; i < n; i++) vc[i] = i + 1;

    while(trial--)
    {
        shuffle(vc.begin(), vc.end(), rng);
        int pos = 0;
        for(int i = 0; i < n; i++)
        {
            if(vc[i] == n) pos = i;
        }
        sum += pos;
    }
    cout << setprecision(10) << fixed << 1.00 * sum / 1000 << "\n";
    **/
    return 0;
}
