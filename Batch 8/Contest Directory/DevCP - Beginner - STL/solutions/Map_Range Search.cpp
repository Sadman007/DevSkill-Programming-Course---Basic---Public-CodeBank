#include <bits/stdc++.h>
using namespace std;

int main()
{
    map <string, int> M;
    map <string, int> :: iterator it, start, ending;

    int q;
    cin >> q;

    while(q--)
    {
        string key;
        int query, x;
        cin >> query;

        if(query == 0)
        {
            cin >> key >> x;
            M[key] = x;
        }

        else if(query == 1)
        {
            cin >> key;
            int ans = 0;
            if(M.find(key) != M.end()) ans = M[key];
            cout << ans << "\n";
        }

        else if(query == 2)
        {
            cin >> key;
            if(M.find(key) != M.end())
                M.erase(key);
        }

        else
        {
            string L, R;
            cin >> L >> R;

            start = M.lower_bound(L);
            ending = M.upper_bound(R);

            for(it = start; it != ending; it++)
                cout << it->first << " " << it->second << "\n";
        }
    }

    return 0;
}
