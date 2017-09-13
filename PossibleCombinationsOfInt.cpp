#include <iostream>
using namespace std;
#define MAX 100

char result[MAX];

void printCombinations(char str[], int index1, int index2) {

	if (str[index1] == '\0') {
		result[index2] = '\0';
		cout << result << endl;
		return;
	}

	int digit = str[index1] - '0'; // convert in int
	char ch = 'A' + digit -1; //ch is the equivalent english char
	result[index2] = ch; //store that character into the result char array
	printCombinations(str, index1 + 1, index2 + 1);

	if (str[index1 + 1] == '\0') return;
	//for considering the next two numbers as a single one
	// 2,3 can be 23.
	int nextDig = str[index1 + 1] - '0';
	int num = 10 * digit + nextDig;
	if (num > 26) return;
	char ch2 = 'A' + num -1 ;
	result[index2] = ch2;
	printCombinations(str, index1 + 2, index2 + 1);

}
int main() {
	char str[MAX];
	cin >> str;

	printCombinations(str, 0, 0);
	return 0;
}