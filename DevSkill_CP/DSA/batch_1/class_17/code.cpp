#include <bits/stdc++.h>
using namespace std;

void TEST_VECTOR_WITH_PAIR()
{
    vector<pair<string, vector<int>>> students_info;

    pair<string, vector<int>> student_info;
    student_info.first = "Md Sadman Sakib";
    student_info.second = {195, 2, 6};

    students_info.push_back(student_info);
    students_info.push_back({"Zahangir", {56, 82, 7}});

    sort(students_info.begin(), students_info.end());

    /// iterator-based looping
    /// auto
    for (auto student_info : students_info)
    {
        auto &[name, rolls] = student_info;
        cout << name << " ";
        sort(rolls.begin(), rolls.end());
        for (auto roll : rolls)
        {
            cout << roll << " ";
        }
        cout << "\n";
    }
}

void TEST_SET()
{
    set<int> st;
    st.insert(2);
    st.insert(1);
    st.insert(10);
    st.insert(10);
    st.insert(5);
    st.insert(10);

    //for (auto elem : st)
    //    cout << elem << " ";
    /// 1 2 5 10
    cout << *(st.lower_bound(4)) << endl;

    //cout << *(st.rbegin()) << "\n";
}

int main()
{
    TEST_SET();
    return 0;
}
