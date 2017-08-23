#include <iostream>
#include <algorithm>
using namespace std;
bool FindTriplet(int arr[], int size) {
	//square each element of the array
	for (int i = 0; i < size; ++i) arr[i] *= arr[i];
	//sort the array
	sort(arr, arr + size);

	for (int i = size - 1; i >= 2; --i) {
		int left = 0;
		int right = i - 1;

		while (left < right) {

			if (arr[left] + arr[right] == arr[i]) return true;

			if (arr[left] + arr[right] > arr[i]) --right;

			else ++left;
		}
	}
	return false;
}
int main() {
	int size; cin >> size;
	int arr[size];
	for (int i = 0; i < size; ++i) cin >> arr[i];
	FindTriplet(arr, size) ? cout << "YES" : cout << "NO";
	return 0;
}
/*Time Complexity:O(N^2) 
Space Complexity: O(1) */