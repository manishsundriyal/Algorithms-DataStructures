#include <iostream>
using namespace std;
int InterpolationSearch(int arr[], int size, int search) {
	int high = size - 1;
	int low = 0;

	while (low <= high && search >= arr[low] && search <= arr[high]) {

		int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (search - arr[low]));

		if (arr[pos] == search) return pos;

		if (arr[pos] < search) low = pos + 1;

		else high = pos - 1;
	}
	return -1;
}
int main() {
	int size; cin >> size;
	//size of the array
	int arr[size];
	for (int i = 0; i < size; ++i) cin >> arr[i];
	//array is defined
	int search; cin >> search;
	//element to be searched
	cout << InterpolationSearch(arr, size, search);
	return 0;
}
/*Time Complexity: If elements are uniformly distributed, then O(log log N)
					Worst case O(N) 
Space Complexity: O(1) /