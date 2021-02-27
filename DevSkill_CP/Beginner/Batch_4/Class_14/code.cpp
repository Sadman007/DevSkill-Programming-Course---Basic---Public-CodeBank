#include <bits/stdc++.h>
using namespace std;

/// int, string, long long, double, float, unsigned int, .... ( primitive data types )
class student
{
public:
    string name, section, cls;
    int roll;
    student()
    {

    }
    student(string name, string section, int roll, string cls)
    {
        this->name = name;
        this->section = section;
        this->roll = roll;
        this->cls = cls;
    }
};

bool lessThan(student &a, student &b) /// lessThan(a, b) --> true (a < b) / false (a == b || a > b)
{
    if(a.roll == b.roll) return a.section < b.section;
    return a.roll < b.roll;
}

int main()
{
    int n;
    cin >> n;
    vector<student>students;
    for(int i = 0; i < n; i++)
    {
        string name, section, cls;
        int roll;
        cin >> name >> section >> roll >> cls;
        student stud(name, section, roll, cls);
        students.push_back(stud);
    }
    sort(students.begin(), students.end(), lessThan);
    puts("OUTPUT>>>>>");
    for(int i = 0; i < n; i++)
    {
        cout << students[i].name << " " << students[i].section << " " << students[i].roll << " " << students[i].cls << "\n";
    }
    return 0;
}

/**
5
rakib a 15 nine
faisal b 63 ten
akib b 34 five
zohir a 10 ten
jalal b 5 eleven
**/
