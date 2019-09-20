/**
    Tag: Number Theory / Observation / BruteForce

    Key Idea: If you have a set of numbers whose GCD is X and you add another integer in this set,
    the final GCD of all the values from the set will be less than or equal to X. It will never increase.
    In order to contribute in the subset with GCD K, an integer has to be a multiple of K at first.
    So if we encounter any integer which is divisible by K, we will take it to our subset. At any point, if
    the GCD of our subset is equal to K, we have found our subset, else NOT.

**/

#include <bits/stdc++.h>
using namespace std;
int arr[100010];

int main()
{
    int n,Q,K;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    scanf("%d",&Q);
    for(int i=0;i<Q;i++)
    {
        scanf("%d",&K);
        int G = 0;
        bool found = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]%K == 0) G = __gcd(G,arr[j]);
            if(G == K)
            {
                puts("Y");
                found = 1;
                break;
            }
        }
        if(found == 0) puts("N");
    }
    return 0;
}
