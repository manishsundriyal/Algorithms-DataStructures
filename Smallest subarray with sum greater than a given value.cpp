#include <iostream>
using namespace std;
int smallestSub(int arr[], int size, int value) {
	int len = size + 1;
	int sum = 0;
	int index1 = 0, index2 = 0;

	for (index2 = 0; index2 < size+1; ++index2) {

		while (sum > value && index1 < size) {
			if ((index2 - index1 < len)) len = index2 - index1;
			sum -= arr[index1];
			++index1;
		}
		if(index2<size) sum += arr[index2];
		
	}
	return len;
}
int main() {
	int size; cin >> size;
	int arr[size];
	for (int i = 0; i < size; ++i) cin >> arr[i];
	int value; cin >> value;
	int result = smallestSub(arr, size, value);
	if (result != size + 1) cout << result;
	else cout << "NOT POSSIBLE";
	return 0;
}
/*Time Complexity:O(N) 
Space Complexity: O(1)*/