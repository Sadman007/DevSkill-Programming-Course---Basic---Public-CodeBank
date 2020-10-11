#include <bits/stdc++.h>
using namespace std;

vector<int>vc(5);

bool gen(int pos, int res)
{
    if(pos == 5) return (res == 23);

    bool plus_call = gen(pos + 1, res + vc[pos]);
    bool minus_call = gen(pos + 1, res - vc[pos]);
    bool mult_call = gen(pos + 1, res * vc[pos]);

    if(plus_call || minus_call || mult_call) return true;
    return false;
}

int main()
{
    while(cin >> vc[0] >> vc[1] >> vc[2] >> vc[3] >> vc[4])
    {
        int zc = 0;
        for(auto it : vc)
        {
            zc += it == 0;
        }
        if(zc == 5) break;

        sort(vc.begin(), vc.end());

        bool is_found = false;

        do
        {
            bool res = gen(1, vc[0]);
            if(res)
            {
                is_found = true;
                break;
            }
        }
        while(next_permutation(vc.begin(), vc.end()));

        if(is_found)
            puts("Possible");
        else
            puts("Impossible");
    }
    return 0;
}
