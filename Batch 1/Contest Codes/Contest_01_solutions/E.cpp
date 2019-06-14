#include <cstdio>
using namespace std;

char buf[100500];
int L[100500];

bool was[100500];

int main()
{
    int n;
    scanf("%d", &n);
    scanf(" %s", buf);
    for (int i = 0; i < n; i++) scanf("%d", &L[i]);

    int curr_pos = 1;

    while (was[curr_pos]==false)
    {
        was[curr_pos] = true;
        if(buf[curr_pos]=='>') curr_pos+=L[curr_pos];
        else curr_pos-=L[curr_pos];
        if (curr_pos <= 0 || curr_pos > n)
        {
            puts("FINITE");
            return 0;
        }
    }
    puts("INFINITE");
}
