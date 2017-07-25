#include <bits/stdc++.h>
using namespace std;
void Merge(int arr[],int left,int mid,int right){
	int i,j,k;
	int n1=mid-left+1;
	int n2=right-mid;

	int L[n1],R[n2];
	//declared two arrays for both the halves
	for(i=0;i<n1;++i) L[i]=arr[left+i];
	for(i=0;i<n2;++i) R[i]=arr[mid+1+i];
	//defined them
	i=0;
	j=0;
	k=left;
	while(i<n1&&j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			++i;
		}
		//if element in left half is smaller or equal to right half element then
		//insert the element in the array and move the index of left half and the array.
		else{
			arr[k]=R[j];
			++j;	
		}
		//similarly for the right half
		++k;
	}
	// cases if one half is empty and the other is still having some elements remaining
	while(i<n1){
		arr[k]=L[i];
		++i;
		++k;
	}
	while(j<n2){
		arr[k]=R[j];
		++j;
		++k;
	}
}
void MergeSort(int arr[],int left,int right){
	if(left<right){

		int mid=(left+right)/2;
		//calculates the middle element of the array
		MergeSort(arr,left,mid);
		//recursion for 1st half of the array
		MergeSort(arr,mid+1,right);
		//recursion for the 2nd half of the array
		Merge(arr,left,mid,right);
		//Merge function call
		//Merge fucntion merges the two sorted halves
	}
}
void PrintArray(int arr[],int n){
	for(int i=0;i<n;++i) cout<<arr[i]<<" ";
}
int main(){
	int n; cin>>n;
	//size of the array
	int arr[n];
	//array defined
	for(int i=0;i<n;++i) cin>>arr[i];
	MergeSort(arr,0,n-1);
	PrintArray(arr,n);
	return 0;
}
//Time Complexity:O(NlongN)
//Space Complexity:O(N)