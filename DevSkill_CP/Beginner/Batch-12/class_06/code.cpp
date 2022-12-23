#include <bits/stdc++.h>
using namespace std;

mt19937 rng(time(0));

long long get_factorial(int n) // [0, 20]
{
    long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

class User
{
public:
    int id;
    string name;
    vector<int> friends_id;

    User();

    void print()
    {
        cout << "name: " << name << "\n";
        cout << "id: " << id << "\n";
        cout << "friends id: " << "\n";
        for (auto id : friends_id)
        {
            cout << id << " ";
        }
        cout << "\n";
        cout << "\n";
    }

    void connect(User& u)
    {
        friends_id.push_back(u.id);
        u.friends_id.push_back(id);
    }

    void show_friends();
};

map<int, User*> id_to_user;

void User::show_friends()
{
    cout << "Showing " << name << "'s friendlist...\n";
    for (auto id : friends_id)
    {
        cout << id_to_user[id]->name << " ";
    }
    cout << "\n\n";
}

User::User()
{
    id = rng();
    id_to_user[id] = this;
}

int main()
{
    User u1;
    u1.name = "Md Sadman Sakib";

    User u2;
    u2.name = "Rabiul";

    u1.connect(u2);

    u1.show_friends();
    u2.show_friends();
    return 0;
}
