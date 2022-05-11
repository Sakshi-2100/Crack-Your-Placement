#include <bits/stdc++.h> 

void merge(long long *arr,long long *temp,int s,int mid,int e,long long int& x) {
	int i=s;
	int j=mid+1;
	int k=s;
	while(i<=mid && j<=e){
		if(arr[i]<=arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
			x += (mid-i+1);
		}
	}
	while(i<=mid){
		temp[k++] = arr[i++];
	}
	while(j<=e){
		temp[k++] = arr[j++];
	}
	//copying temp elements  back to the array
	for(int i=s;i<=e;i++)
		arr[i]=temp[i];
}
void mergesort(long long *arr,long long *temp,int s,int e,long long int& x) {
	if(s>=e)
		return;
	int mid = s+(e-s)/2;
	mergesort(arr,temp,s,mid,x);
	mergesort(arr,temp,mid+1,e,x);
	merge(arr,temp,s,mid,e,x);
}


long long getInversions(long long *arr, int n){
    // Write your code here.
	long long int count=0;
	long long temp[n];
	mergesort(arr,temp,0,n-1,count);
	return count;
}
