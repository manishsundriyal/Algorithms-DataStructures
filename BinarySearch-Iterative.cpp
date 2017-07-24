/* NOTE: In BinarySearch we will assume that the given array is already sorted.
 If not then sort the array first.
*/
#include<iostream>
using namespace std;
int BinarySearch(int arr[], int size, int searchFor) {
	int low = 0, high = size - 1;
	//search for the element until the low index is smaller than the high index OR if the element if found.
	while (low <= high) {
		int mid = (low + high) / 2;
		//CASE 1: if element at mid index is the element we were looking for.
		// return the mid index as the positon at which element is found.
		if (arr[mid] == searchFor) return mid;
		//CASE 2: If element at mid index is smaller than the element we were looking for.
		if (arr[mid] < searchFor)	low = mid + 1; //then ignore the left half of the array.
		//CASE 3: If element at mid index is greater than the element we were looking for.
		else high = mid - 1; //ignore the right half of the array.
	}
	//If element is not found then we will reach here
	return -1; // -1 represents that element not found.
}
int main() {
	int size; cin >> size;
	int arr[size];
	//input the elements to the array.
	for (int i = 0; i < size; ++i) cin >> arr[i];
	int searchFor; cin >> searchFor;
	//calll of BinarySearch function
	//prints out the position of the element were wee found the element, -1 is element is not found.
	cout << BinarySearch(arr, size, searchFor);
	return 0;
}

/*TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(1)*/