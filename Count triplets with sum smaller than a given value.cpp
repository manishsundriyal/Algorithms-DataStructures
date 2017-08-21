#include <iostream>
#include <algorithm>
using namespace std;
int countTriplets(int arr[], int size, int sum) {

	sort(arr, arr + size);
	//sort the array, to decrease the time complexity
	int ans = 0;
	//initializing the number of such triplets to 0
	for (int i = 0; i < size - 2; ++i) {

		int j = i + 1, k = size - 1;

		while (j < k) {
			if (arr[i] + arr[j] + arr[k] >= sum) --k;
			//if the sum is greater than the sum value
			//decrease the k index
			else {
				ans += (k - j);
				++j;
				//hence there can be total k-j third elements
			}
		}
	}
	return ans;
}
int main() {
	int size; cin >> size;
	//size of the array
	int arr[size];
	for (int i = 0; i < size; ++i) cin >> arr[i];
	//array defination
	int sum; cin >> sum;
	//sum, the sum of the triplets should be smaller than this
	cout << countTriplets(arr, size, sum) << endl;
	return 0;
}
/*Time Complexity:O(N^2) 
Space Complexity: O(1)*/