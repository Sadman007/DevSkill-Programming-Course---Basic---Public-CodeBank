#include <bits/stdc++.h>
using namespace std;

struct student_info
{
    string name, section, school, mobile;
    int id;
    vector<int>friendList;
};

void print_student_info(student_info var)
{
    cout << "student name : " << var.name << "\n";
    cout << "student id : " << var.id << "\n";
    cout << "student section : " << var.section << "\n";
    cout << "student school : " << var.school << "\n";
    cout << "student mobile : " << var.mobile << "\n";
    cout << "student friendlist : \n";
    for(auto frd : var.friendList)
    {
        cout << frd << " ";
    }
    cout << "\n";
}

vector<student_info>students;

int main()
{
    ///student_info
    /**
        name        -> string
        id          -> int
        section     -> string
        school      -> string
        mobile      -> string
        friendList  -> vector<int>
    **/
    student_info nahid;

    nahid.name = "Nahid Chowdhury";
    nahid.id = 123;
    nahid.section = "A";
    nahid.school = "XYZ";
    nahid.mobile = "017xxxxxxx";
    nahid.friendList.push_back(1);
    nahid.friendList.push_back(2);
    nahid.friendList.push_back(3);

    students.push_back(nahid);

    print_student_info(students[0]);



    return 0;
}
