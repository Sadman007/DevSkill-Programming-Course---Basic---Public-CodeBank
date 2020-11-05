#include <bits/stdc++.h>
using namespace std;

/**
/// 1,2,3,4,5,6
/// 2 4 6
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

int n, val;
scanf("%d", &n);
for(int i = 0; i < n; i++)
{
    scanf("%d", &val);
    if(i % 2 == 1) printf("%d\n", val);
}
**/

/**
    Section: Nested Loop

    Ex: 1
        int n;
        cin >> n;

        for(int value = 1; value <= n; value++)
        {
            /// namta print kora
            for(int i = 1; i <= 10; i++)
            {
                printf("%d x %d = %d\n", value, i, value * i);
            }
            printf("\n");
        }

    Ex: 2
        int n, m;
        int grid[10][10];
        cin >> n >> m; /// n = number of rows, m = number of columns

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf("%d", &grid[i][j]);
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                printf("%d ", grid[i][j]);
            }
            puts("");
        }

**/

/**
    substr()
            string str;
            getline(cin, str); /// devskill corporation
            cout << str << "\n";
            string sub = str.substr(3, 8);
            cout << sub << " " << sub.size() << "\n";
**/

/**
    string str[100];
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        getline(cin, str[i]);
    }
    for(int i = 0; i < n; i++)
    {
        cout << str[i] << " " << str[i].size() << "\n";
    }
**/

int main()
{
    //freopen("input.txt", "r", stdin);
    int sum = 0;
    int var1, var2;
    while(cin >> var1 >> var2)
    {
        sum += var1 + var2;
    }
    cout << "Sum is : " << sum << "\n";
    return 0;
}
