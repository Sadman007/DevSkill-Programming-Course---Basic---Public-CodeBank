#include <bits/stdc++.h>
using namespace std;


int main()
{   int ff=-1;
    string text,part;
    //text=("aabaaa");
    //part=("aa");
    cin>>text;
    cin>>part;

    int txt_len = text.size();
    int part_len = part.size();

    for(int i=0; i<txt_len;i++){
        ff=text.find(part,i);
        cout << ff << "\n";
    }
   return 0;
}
