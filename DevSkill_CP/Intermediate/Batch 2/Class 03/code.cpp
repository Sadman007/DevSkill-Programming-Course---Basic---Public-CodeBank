#include <bits/stdc++.h>
using namespace std;
#define MOD 100000
#define MAX 1100010

/// 10^5 + 10^6 = 1100000 ~ 1000000

/**
    10^8 ta task complete korte on average CPU er time lage 1 second

    10^6 ta task complete korte hobe

    10^8 ta task ..... 1s
    1 ta task .....    1/10^8 = 10^(-8)s
    10^6 ta task ... 10^6 * 10^(-8) = 0.01 s
**/

int output[5000010]; /// 2*10^7/ 10^6 = 20
int cnt[5000010];
int fibonacci[5000010];
int fib[1100100];

void CountingSort(int *arr,int n)
{
    int mn = *min_element(arr,arr+n);
    int mx = *max_element(arr,arr+n);

    memset(cnt,0,sizeof cnt);

    for(int i=0; i<n; i++)
    {
        cnt[arr[i]-mn]++;
    }
    for(int i=1; i<(mx-mn+2); i++)
    {
        cnt[i]+=cnt[i-1];
    }
    for(int i=n-1; i>=0; i--)
    {
        output[cnt[arr[i]-mn]-1] = arr[i];
        cnt[arr[i]-mn]--;
    }
    for(int i=0; i<n; i++)
        arr[i] = output[i];
}



int main()
{
    fib[1] = 0;
    fib[2] = 1;
    for(int i=3;i<=MAX;i++) /// O(MAX)
    {
        fib[i] = (fib[i-1]+fib[i-2])%MOD;
    }

    int testCase;
    scanf("%d",&testCase);
    for(int cs=1;cs<=testCase;cs++)
    {
        int A,B;
        scanf("%d%d",&A,&B);
        int idx = 0;
        for(int i=A;i<=(A+B);i++)
        {
            fibonacci[idx] = fib[i];
            idx++;
        }
        //sort(fibonacci,fibonacci+idx); /// O(NlogN)
        /**
            10^5
            100000*log2(100000)
            counting sort - O(N+R)
            R = max_elem_of_array - min_elem_of_array + 1;
            R = 99999-0+1 = 10^5
        **/
        CountingSort(fibonacci,idx);
        int len;

        if(idx>100) len = 100;
        else len = idx;

        /// len = min(100,idx);

        printf("Case %d:",cs);
        for(int i=0;i<len;i++)
        {
            printf(" %d",fibonacci[i]);
        }
        printf("\n");
    }


    /**
    stringstream ss;
    string stringNum = "12345";
    int intNum;
    ss << stringNum;
    ss >> intNum;
    cout << intNum << "\n";
    **/

    return 0;
}
