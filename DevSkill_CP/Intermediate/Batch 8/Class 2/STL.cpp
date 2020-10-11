#include <bits/stdc++.h>
using namespace std;

///int arr[1000][100000]; /// 10^3 * 10^5 = 10^8 = 4 * 10^2 MB

void VECTOR()
{
    /**
    vector
        1000 ta array lagbe.
        protita array er size 1<=L<=10^5
        1000<=sum_of_length<=10^6

        processor 1 second e 10^8 ta execution complete korte pare

        vector<int>vc;

        vc.push_back(5);
        vc.push_back(34534);
        vc.push_back(-15);
        vc.push_back(-20);
        vc.push_back(0);

        sort(vc.begin(), vc.end()); /// Intro Sort = Quick Sort + Heap Sort / Merge Sort + Insertion Sort , O(NlogN)

        for(int i = 0; i < vc.size(); i++)
        {
            cout << vc[i] << " ";
        }
        cout << "\n";
        cout << vc.size() << "\n";
    **/
}

void SET()
{
/**
        You are given N integers. Find the number of distinct integers among them.

        9
        1 2 1 2 3 1 2 2 3

        1 1 1 2 2 2 2 3 3
        cnt = 3

        self balancing binary search tree
    **/
    set<int>my_set; /// item gulo ascending order e sorted thake
    int n;
    cin >> n; /// equivalent to scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        my_set.insert(val);
    }
    for(int val : my_set)
        cout << val << " ";
    //cout << my_set.size() << "\n"; /// equivalent to printf("%d\n", my_set.size());

    //cout << my_set.size() << "\n";
}

struct info
{
    string address;
    int roll;
    info(){}
};

int main()
{
    /**
    1) negative index!
    2) huge index!
    3) index er range unknown!
    **/
    /**

    map<info, string>mp; /// <key_type, value_type>
    info info_tasmia;
    info_tasmia.address = "BD";
    info_tasmia.roll = 100;

    //mp["Tasmia"] = info_tasmia;

    //cout << mp["Tasmia"].address << " " << mp["Tasmia"].roll << "\n";
    **/
    map<int, int>mp;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int key, value;
        cin >> key >> value; /// scanf("%d %d", &key, &value);
        mp[key] = value;
    }
    for(auto item : mp) cout << item.first << " " << item.second << "\n";
    return 0;
}
