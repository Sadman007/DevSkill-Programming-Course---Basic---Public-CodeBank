#include <bits/stdc++.h>
using namespace std;

void t1()
{
   /**
        /// is s2 a subsequence of s1?
        string s1, s2;
        cin >> s1 >> s2;

        int redP, greenP;
        redP = greenP = 0;

        while(redP < s1.size() && greenP < s2.size())
        {
           if(s1[redP] == s2[greenP])
           {
              greenP++;
           }
           redP++;
        }

        if(greenP == s2.size()) cout << "1\n";
        else cout << "0\n";
    **/
}

int main()
{
    string s;
    cin >> s;
    int greenP, redP;
    greenP = 0;
    redP = s.size() - 1;
    while(greenP <= redP)
    {
        if(s[greenP] == s[redP])
        {
            greenP++;
            redP--;
        }
        else break;
    }
    if(redP < greenP) cout << "1\n";
    else cout << "0\n";
    return 0;
}
