#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void QUEUE() /// FIFO -> First In First Out
{
    queue<int>Q;
    Q.push(1);
    Q.push(2);
    Q.push(3); /// insertion -- Q (1, 2, 3)
    cout << Q.front() << "\n"; /// 1
    Q.pop();
    cout << Q.front() << "\n"; /// 2
}

void PRQ()
{
    priority_queue<int>PQ; /// PQ -> (15 21 18 67 42) PQ.front() => 67 , PQ.pop();
    /// PQ -> (15 21 18 42) PQ.front() => 42 , PQ.pop();
    /// PQ -> (15 21 18) PQ.front() => 21 , PQ.pop();
    /// PQ -> (15 18) PQ.front() => 18 , PQ.pop();
    /// PQ -> (15) PQ.front() => 15 , PQ.pop();
    /// Heap Sort
    PQ.push(15); /// O(logN) : N = |PQ|
    PQ.push(21);
    PQ.push(18);
    PQ.push(67);
    PQ.push(42);

    while(!PQ.empty())
    {
        cout << PQ.top() << "\n"; /// O(1)
        PQ.pop(); /// O(logN) : N = |PQ|
    }
}

int nahid[5000]; /// 4 bytes * 5000 -> 20000 bytes -> 20000 / 1000 = 20 KB = 20 / 1000 MB = 0.02 MB
long long shakil[1000000]; /// 8 bytes * 10^6 -> 8 * 10^6 bytes * 10^-6 -> 8 MB

int main()
{
    string str;
    cin >> str;
    cout << str << " " << str.size() << "\n";
    return 0;
}
