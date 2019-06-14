#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int cost;

void SelectionSort(int *arr,int n,bool stable=0)
{
    cost = 0;
    for(int i=0; i<n-1; i++)
    {
        int minIdx = i;
        for(int j=i+1; j<n; j++)
        {
            cost++;
            if(arr[j]<arr[minIdx])
            {
                minIdx = j;
            }
        }
        if(stable)
        {
            int key = arr[minIdx];
            while(minIdx>i)
            {
                cost++;
                arr[minIdx] = arr[minIdx-1];
                --minIdx;
            }
            arr[i] = key;
        }
        else
            swap(arr[i],arr[minIdx]);
    }
}

void InsertionSort(int *arr,int n)
{
    cost = 0;
    for(int i=1; i<n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key)
        {
            cost++;
            arr[j+1] = arr[j--];
        }
        arr[j+1] = key;
    }
}

void QuickSort(int *arr,int lo,int hi)
{
    int pivot = arr[(lo+hi)/2];
    int L = lo;
    int R = hi;
    while(L<=R)
    {
        while(arr[L]<pivot)
            L++;
        while(arr[R]>pivot)
            R--;
        if(L<=R)
        {
            swap(arr[L],arr[R]);
            L++,R--;
        }
    }
    if(lo<R)
        QuickSort(arr,lo,R);
    if(L<hi)
        QuickSort(arr,L,hi);
}

void BubbleSort(int *arr,int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

void CountingSort(int *arr,int n)
{
    int output[n+1];
    int mn = *min_element(arr,arr+n);
    int mx = *max_element(arr,arr+n);
    int cnt[mx-mn+5];

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

void CSort(int *arr,int n,int exp)
{
    int output[n+1];

    int cnt[35];

    memset(cnt,0,sizeof cnt);

    for(int i=0; i<n; i++)
    {
        cnt[(arr[i]/exp)%10]++;
    }
    for(int i=1; i<=30; i++)
    {
        cnt[i]+=cnt[i-1];
    }
    for(int i=n-1; i>=0; i--)
    {
        output[cnt[(arr[i]/exp)%10]-1] = arr[i];
        cnt[(arr[i]/exp)%10]--;
    }
    for(int i=0; i<n; i++)
        arr[i] = output[i];
}

void RadixSort(int *arr,int n)
{
    int mxValue = *max_element(arr,arr+n);
    for(int exp=1; mxValue/exp>0; exp*=10)
    {
        CSort(arr,n,exp);
    }
}

void Sort(int *arr,int L,int M,int R)
{
    int s1 = M-L+1;
    int s2 = R-M;

    int v1[s1],v2[s2];

    for(int i=0;i<s1;i++)
    {
        v1[i] = arr[L+i];
    }
    for(int i=0;i<s2;i++)
    {
        v2[i] = arr[M+1+i];
    }
    int i,j,k;
    i = j = 0;
    k = L;

    while(i<(s1) && j<(s2))
    {
        if(v1[i]<=v2[j])
        {
            arr[k++] = v1[i];
            i++;
        }
        else
        {
            arr[k++] = v2[j];
            j++;
        }
    }
    while(i<s1)
    {
        arr[k++] = v1[i++];
    }
    while(j<s2)
    {
        arr[k++] = v2[j++];
    }
}

void MergeSort(int *arr,int L,int R)
{
    if(L<R)
    {
        int M = L+(R-L)/2;
        MergeSort(arr,L,M);
        MergeSort(arr,M+1,R);
        Sort(arr,L,M,R);
    }
}


void MapSort(int *arr,int n)
{
    map<int,int>mp;
    int idx = 0;
    for(int i=0;i<n;i++) mp[arr[i]]++;
    for(auto it : mp)
    {
        int cnt = it.second;
        while(cnt--) arr[idx++] = it.first;
    }
}

void SetSort(int *arr,int n)
{
    multiset<int>st;
    int idx = 0;
    for(int i=0;i<n;i++) st.insert(arr[i]);
    for(auto it : st)
    {
        arr[idx++] = it;
    }
}
int arr[5000010];
int sz[] = {5,50,500,5000,50000,100000,150000,200000,250000,300000,350000,400000,450000,500000};

bool sortValidity(int *a,int n)
{
    int a2[n+1];
    for(int i=0;i<n;i++) a2[i] = a[i];
    sort(a2,a2+n);
    for(int i=0;i<n;i++)
    {
        if(a2[i]!=a[i]) return 0;
    }
    return 1;
}

int main()
{
    int len = 14;
    for(int idx=0; idx<len; idx++)
    {
        for(int i=0; i<sz[idx]; i++)
            arr[i] = i;
        shuffle(arr,arr+sz[idx],rng);
        auto st = high_resolution_clock::now();
        //QuickSort(arr,0,sz[idx]-1);
        //SelectionSort(arr,sz[idx]);
        //InsertionSort(arr,sz[idx]);
        //BubbleSort(arr,sz[idx]-1);
        //CountingSort(arr,sz[idx]-1);
        //RadixSort(arr,sz[idx]);
        //MergeSort(arr,0,sz[idx]-1);
        MapSort(arr,sz[idx]);
        //SetSort(arr,sz[idx]);
        //if(!sortValidity(arr,sz[idx])) puts("ERROR");
        auto en = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(en - st);
        cout << sz[idx] << ": " << duration.count() << " " << duration.count()/1000.0 << "\n";
    }
    return 0;
}
