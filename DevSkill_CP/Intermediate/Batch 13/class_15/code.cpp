#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
int phi[MAX + 5];

// TC: O(NlogN)
void generatePhi(int n)
{
    for (int i = 1; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

void mergeThem(vector<int> &vc, int L, int M, int R)
{
    // TODO
}

void mergeSort(vector<int> &vc, int L, int R) /// mergeSort(vc, 3, 7);
{
    if (L < R)
    {
        int M = (L + R) / 2;
        mergeSort(vc, L, M); /// vc[L...M]
        mergeSort(vc, M + 1, R); /// vc[M + 1...R]
        // merge them
        mergeThem(vc, L, M, R);
    }
}

int main()
{
    // generatePhi(MAX);
    mergeSort(vc, 0, vc.size() - 1);
    return 0;
}
