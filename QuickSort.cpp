#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int low,int high){
	int pivot=arr[high];
	//setting the piviot to the right most element
	int i=(low-1);
	//setting index of the smaller element
	for(int j=low;j<=high-1;++j){
		if(arr[j]<=pivot){
			//if arr[j] element is smaller than equal to pivot
			++i;
			//increment of the index of smaller element.
			swap(arr[i],arr[j]);
			//swaping of smaller and bigger element
		}
	}
	swap(arr[i+1],arr[high]);
	return (i+1);
}
void QuickSort(int arr[],int low,int high){
	if(low<high){
		int pi=partition(arr,low,high);
		//pi will be the partioning index
		QuickSort(arr,low,pi-1);
		//similarly recursion call for left half.
		QuickSort(arr,pi+1,high);	
		//similarly recursion call for right half.
	}
}
void PrintArray(int arr[],int n){
	for(int i=0;i<n;++i) cout<<arr[i]<<" ";
}
int main(){
	int n; cin>>n;
	//size of the array
	int arr[n];
	//array declared
	for(int i=0;i<n;++i) cin>>arr[i];
	//array defined
	QuickSort(arr,0,n-1);
	//call of QuickSort Function
	// with parameters arr,low,high
	PrintArray(arr,n);
	return 0;
}
//Time Complexity:O(n^2), actually its Theta(N^2) more specifically
// It's worst case time complexity can be optimized upto logN
// By the QuickSort Tail Call Optimization method
//Space Complexity:O(1)
/*QuickSort is preferred over MergeSort for sorting arrays because its an 
in-place sort (It dosen't require any extra storage) whereas in merge sort
	extra storage.*/