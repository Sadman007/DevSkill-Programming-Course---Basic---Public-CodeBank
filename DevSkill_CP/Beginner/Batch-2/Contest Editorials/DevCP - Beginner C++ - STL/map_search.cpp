#include <bits/stdc++.h>
using namespace std;

int main(){
	string key;
    int q, i, value;
    cin >> q;
    map <string, int> thisMap;
    while(q--)
    {
        scanf("%d", &i);
        if(i == 0)
        {
        	cin >> key >> value;
            thisMap[key] = value;
        }
        else
        {
        	cin >> key;
            if(thisMap.find(key) != thisMap.end())
            	cout << thisMap[key] << "\n";
            else
            	cout << "0\n";
        }
    }
    return 0;
}