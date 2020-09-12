#include<bits/stdc++.h>
using namespace std;

long long merge(int a[],int l,int mid,int r)
{
	int i,j,k;
	int n1 = mid - l + 1;
	int n2 = r - mid;
	int L[n1],R[n2];
	for(i=0;i<n1;i++){
		L[i] = a[l+i];
	}
	for(j=0;j<n2;j++){
		R[j] = a[mid+1+j];
	}
	i = 0;
	j = 0;
	k = l;
	long long count = 0;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
			count = count + (n1-i);
		}
		k++;
	}
	while(i<n1){
		a[k] = L[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k] = R[j];
		j++;
		k++;
	}
	return count;
}
long long mergeSort(int a[],int l,int r){
	long long count = 0;
	if(l<r){
		int mid = (l+r)/2;
		count = mergeSort(a,l,mid);
		count += mergeSort(a,mid+1,r);
		count += merge(a,l,mid,r);
	}
	return count;
}
int a[1000000];
int main()
{
	int i,j,n;
	while(scanf("%d",&n)){
		if(n==0){
			return 0;
		}
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		long long total = mergeSort(a,0,n-1);
		printf("%lld\n",total);
	}
	return 0;
}