#include <iostream>
using namespace std;
void InsertionSort(int arr[],int n){
	int i,key,j;
	for(int i=1;i<n;++i){
		key=arr[i];
		// key stores the arr[i] value for future use.
		j=i-1;

		while(j>=0&&arr[j]>key){
			//j>=0 represents that if there exist an element
			//arr[j] represents that if the previous value is greater or not.
			//If it is greater, then it should be sorted otherwise not.
			arr[j+1]=arr[j];
			j=j-1; // same as --j
		}
		arr[j+1]=key; //restores the value stored in key variable.
	}
}
void printArray(int arr[],int n){
	for(int i=0;i<n;++i) cout<<arr[i]<<" ";
}
int main(){
	int n; cin>>n;
	//size of the array
	int arr[n];
	//declared integer array of size n.
	for(int i=0;i<n;++i) cin>>arr[i];
	//defining elements of the array/
	InsertionSort(arr,n);
	printArray(arr,n);
	return 0;
}
//Time Complexity: O(n^2)
//Space Complexity: O(1)