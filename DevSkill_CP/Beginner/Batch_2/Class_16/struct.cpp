#include <bits/stdc++.h>
using namespace std;

struct studentInfo
{
    string name;
    int roll, cls;
};

bool cmp(studentInfo a, studentInfo b) /// cmp({A,2,3}, {B,1,4}) 0 < 1 --> true
{
    if(a.roll < b.roll) return true;
    return false;
}

int main()
{
    // data-type variable_name[size]
    studentInfo students[100];

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> students[i].name >> students[i].roll >> students[i].cls;
    }

    /// bubble-sort --> int arr[100]

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(students[i].roll > students[j].roll)
            {
                swap(students[i], students[j]);
                /**
                    studentInfo tmp = students[i];
                    students[i] = students[j];
                    students[j] = tmp;
                **/
            }
        }
    }

    /// built in sort (IntroSort)
    sort(students, students + n, cmp);

    for(int i = 0; i < n; i++)
    {
        cout << students[i].name << " " <<  students[i].roll << " " << students[i].cls << "\n";
    }

    return 0;
}
