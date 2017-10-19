#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int partition(int arr[],int left,int right){
	int temp=arr[right],i=left;
	for(int j=left;j<=right-1;++j){
		if(arr[j]<=temp){
			swap(arr[i],arr[j]);
			++i;
		}
	}
	swap(arr[i],arr[right]);
	return i;
}
int randomPartition(int arr[],int left,int right){
	int n=right-left+1;
	int pivot=rand()%n;
	swap(arr[left+pivot],arr[right]);
	return partition(arr,left,right);
}
int FindKthSmallest(int arr[],int left,int right,int k){
	
	if(k<=0) return -1;
	if(k>right-left+1) return -1;

	int pos=randomPartition(arr,left,right);

	if(pos-left==k-1) return arr[pos];
	if(pos-left>k-1) return FindKthSmallest(arr,left,pos-1,k);
	else return FindKthSmallest(arr,pos+1,right,k-pos+left-1);	
}
int main(){
	int size;
	cin>>size;
	int *arr= new int[size];
	for(int i=0;i<size;++i) cin>>arr[i];
	int k;
	cin>>k;
	cout<<FindKthSmallest(arr,0,size-1,k);
	return 0;
}