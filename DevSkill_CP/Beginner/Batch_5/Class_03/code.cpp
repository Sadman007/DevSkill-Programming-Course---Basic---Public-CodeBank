#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>myVector; /// {}
    myVector.push_back(3); /// {3}
    myVector.push_back(2); /// {3, 2}
    myVector.push_back(1); /// {3, 2, 1}

    sort(myVector.begin(), myVector.end()); /// Intro Sort -> {Insertion, Quick, Heap}

    for(int i = 0; i < myVector.size(); i++)
    {
        cout << myVector[i] << " ";
    }

    //cout << myVector.size() << endl;
}
