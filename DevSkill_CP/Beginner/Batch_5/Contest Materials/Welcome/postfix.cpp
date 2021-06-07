#include <bits/stdc++.h>
using namespace std;

int main()
{
    string expr;
    while(getline(cin, expr)) {
        vector<string>terms;
        stringstream ss(expr);
        string wd;
        stack<double>value;
        while(getline(ss, wd, ' ')) {
            terms.push_back(wd);
        }
        // now, we have our space separated terms for each input line
        // we could have done it without the additional vector. but anyways
        for(auto exp : terms) {
            if(exp == "+" || exp == "-" || exp == "*" || exp == "/") {
                double v2 = value.top();
                value.pop();
                double v1 = value.top();
                value.pop();
                double curr = 0.0;
                if(exp == "+") curr = v1 + v2;
                if(exp == "-") curr = v1 - v2;
                if(exp == "*") curr = v1 * v2;
                if(exp == "/") curr = v1 / v2;
                value.push(curr);
            }
            else {
                value.push(stod(exp));
            }
        }
        cout << setprecision(4) << fixed << value.top() << "\n";
    }
    return 0;
}
