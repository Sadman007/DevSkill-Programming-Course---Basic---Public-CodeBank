#include <bits/stdc++.h>
using namespace std;

/**
    Student
        - name
        - roll
        - dept
        - phone
**/

struct Student
{
    string name;
    long long roll;
    string dept, phone;

    void print_info()
    {
        cout << name << " " << roll << " " << dept << " " << phone << "\n";
    }
};

int main()
{
    /**
    Student s1;
    s1.name = "Mr A";
    s1.roll = 1231;
    s1.dept = "CSE";
    s1.phone = "0987394";
    s1.print_info();

    Student s2;
    s2.name = "Mr X";
    s2.roll = 122331;
    s2.dept = "EEE";
    s2.phone = "657465";
    s2.print_info();
    **/
    string str = "10 20 30 40";
    stringstream ss;
    ss << str;

    string token;
    while(ss >> token)
    {
        cout << token << "\n";
    }
    return 0;
}
