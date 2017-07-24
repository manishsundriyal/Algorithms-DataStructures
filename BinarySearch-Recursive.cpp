/* NOTE: In BinarySearch we will assume that the given array is already sorted.
 If not then sort the array first.
*/
#include<iostream>
using namespace std;
int BinarySearch(int arr[],int low,int high,int searchFor){
	if(low>high) return -1;//If element is not found in the array.
	int mid=(low+high)/2;
	//CASE 1: if element at mid index is the element we were looking for.
	// return the mid index as the positon at which element is found.
	if(arr[mid]==searchFor) return mid;
	//CASE 2: If element at mid index is smaller than the element we were looking for.
	if(arr[mid]<searchFor) return BinarySearch(arr,mid+1,high,searchFor);
	//CASE 3: If element at mid index is greater than the element we were looking for.	
	return BinarySearch(arr,low,mid-1,searchFor);
}
int main(){
	int size; cin>>size;
	int arr[size];
	for(int i=0;i<size;++i) cin>>arr[i];
	int searchFor; cin>>searchFor;
	cout<<BinarySearch(arr,0,size-1,searchFor);
	return 0;
}
	/*TIME COMPLEXITY: O(log n)
	SPACE COMPLEXITY: O(log n) for the recursion call stack*/