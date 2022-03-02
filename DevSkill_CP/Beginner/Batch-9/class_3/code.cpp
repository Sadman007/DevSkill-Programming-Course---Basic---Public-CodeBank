#include <bits/stdc++.h>
using namespace std;

int main()
{
    /// array of int    -> int arr[10];
    /// 2D array of int -> int arr[10][10];
    /// vector of int   -> vector<int> vec;
    /// array of (vector of int) -> vector<int> vec[10];
    /// vector of vector -> vector<vector<int>> vec;

    /*
    int n = 5, m = 5;
    int returned_value = scanf("%d %d", &n, &m);
    printf("%d %d\n", n, m);
    printf("returned value = %d\n", returned_value);
    */

    /*
    freopen("input.txt", "r", stdin);
    int n;
    vector<int> nums;

    while(scanf("%d", &n) == 1)
    {
        //printf("value %d\n", n);
        nums.push_back(n);
    }

    printf("Input is complete\n");
    for (auto num : nums) /// nums = {1, 2, 3}
    {
        printf("%d ", num);
    }
    */

    int T;
    cin >> T;
    getchar();
    while(T-- > 0)
    {
        string str;
        getline(cin, str);
        cout << "size: " << str.size() << "\n";
        cout << "content: " << str << "\n";
    }
    return 0;
}
