#include<bits/stdc++.h>
using namespace std;
#define left L,(L+R)/2,nd+nd
#define right (L+R)/2+1,R,nd+nd+1

const int MAXN = 100010; /// 1e5 + 10

int arr[MAXN];
vector<int> tree[4 * MAXN];

void MergeTree(int L,int R,int nd)
{
    auto &tleft=tree[nd+nd];
    auto &tright=tree[nd+nd+1];
    int iL=0,iR=0;
    while(iL<tleft.size() && iR<tright.size())
    {
        if(tleft[iL]<=tright[iR]) tree[nd].push_back(tleft[iL++]);
        else tree[nd].push_back(tright[iR++]);
    }
    while(iL<tleft.size()) tree[nd].push_back(tleft[iL++]);
    while(iR<tright.size()) tree[nd].push_back(tright[iR++]);
}

void BuildTree(int L, int R, int nd)
{
    if (L > R) return;
    if (L == R)
    {
        tree[nd].push_back(arr[L]);
        return;
    }
    BuildTree(left);
    BuildTree(right);
    MergeTree(L,R,nd);
}

int Query(int L,int R,int nd,int l,int r,int val)
{
    if(R<l || r<L) return 0;
    if(l<=L && R<=r)
    {
        int k=upper_bound(tree[nd].begin(),tree[nd].end(),val)- tree[nd].begin();
        return k;
    }
    int qleft=Query(left,l,r,val);
    int qright=Query(right,l,r,val);
    return qleft+qright;
}

void compress(vector<int> &nums)
{
    /**
        arr = {10, 3, 7, 17, 4, 15}
       nums = {3, 4, 7, 10, 15, 17}
        arr = {3, 0, 2, 5, 1, 4}
    **/
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++)
    {
        arr[i] = lower_bound(nums.begin(), nums.end(), arr[i]) - nums.begin();
    }
}

int find_kth_smallest_in_range(int l, int r, int k, int N, vector<int> &nums) /// 0-based l, r
{
    int L = 0, R = N - 1;
    while(L < R)
    {
        int M = (L + R) / 2;
        int ub = Query(0, N - 1, 1, l, r, M);
        bool isNo = ub <= k;
        if (isNo)
        {
            L = M + 1;
        }
        else
        {
            R = M;
        }
    }
    return nums[L];
}

int main()
{
    int N, Q;
    scanf("%d %d",&N, &Q);
    vector<int>nums(N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        nums[i] = arr[i];
    }
    compress(nums);
    BuildTree(0, N - 1, 1);
    while(Q--)
    {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", find_kth_smallest_in_range(l - 1, r - 1, k - 1, N, nums));
    }
    return 0;
}
