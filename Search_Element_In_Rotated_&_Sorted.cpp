#include <iostream>
using namespace std;
int BinarySearch(int arr[],int low,int high,int key){

	if(low>high) return -1;
	//base case
	int mid=(low+high)/2;
	//calculate mid element
	if(arr[mid]==key) return mid;
	//key value is at mid index
	if(arr[mid]>key) return BinarySearch(arr,low,mid-1,key);
	//key value somewhere in the left half
	return BinarySearch(arr,mid+1,high,key);
	//If nothing of the above works out 
	//This shows the element is somewhere in the right half
}
int findPivot(int arr[], int low, int high) {
	if (low > high) return -1;
	if (high == low) return low;
	//base cases
	int mid = (low + high) / 2;
	//calculating the mid index
	if (mid < high && arr[mid] > arr[mid + 1]) return mid;
	// If the pivot is at the mid index
	if (mid > low && arr[mid] < arr[mid - 1]) return (mid - 1);
	// If the pivot is at one step left to the mid element
	if (arr[low] >= arr[mid]) return findPivot(arr, low, mid - 1);
	// If the mid index is in the right half 
	return findPivot(arr, mid + 1, high);
	// If the mid index is in the left half

}
int PivotBinarySearch(int arr[], int size, int key) {

	int pivot = findPivot(arr, 0, size - 1);
	
	if(pivot==-1) return BinarySearch(arr,0,size-1,key);
	//If the array is not rotated(so simple binary search for that sorted array)
	if(arr[pivot]==key) return pivot;
	//If the key found at the pivot index
	if(arr[0]<=key) return BinarySearch(arr,0,pivot-1,key);
	//if the first(low) index element is smaller than the key value 
	// this means the value is somewhere at left half
	return BinarySearch(arr,pivot+1,size-1,key);
	//If nothing above works out, then it means 
	// the key value is somewhere at right half
}
int main() {
	int size; cin >> size;
	//size of the array
	int arr[size];
	//array declared
	for (int i = 0; i < size; ++i) cin >> arr[i];
	//array defined
	int key; cin >> key;
	//key value to search for
	int index = PivotBinarySearch(arr, size, key);
	if(index!=-1) cout<<index;
	else cout<<"Not Found";
	return 0;
}
/*Time Complexity: O(logN)
Space Complexity: O(1)/