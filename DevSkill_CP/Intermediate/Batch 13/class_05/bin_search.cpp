#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long K, N;
    cin >> N >> K;
    if (K > 100000) cout << "-1\n";
    else
    {
        vector<long long> divs;
        for (long long i = 1; i * i <= N; i++)
        {
            if (N % i == 0)
            {
                divs.push_back(i);
                if (i * i != N) divs.push_back(N / i);
            }
        }
        sort(divs.begin(), divs.end());
        if (divs.size() < K) cout << "-1\n";
        else cout << divs[K - 1] << "\n";
    }
    return 0;
}
