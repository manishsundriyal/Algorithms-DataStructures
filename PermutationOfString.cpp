#include <iostream>
using namespace std;
void Permuatation(char str[], int be) {

	if (str[be] == '\0') {
		cout << str << endl;
	}
	// base case
	for (int i = be; str[i] != '\0'; ++i) {
		swap(str[i], str[be]);
		//swap the char at [i] and [be]
		Permuatation(str, be + 1);
		//recursive call increase the be
		swap(str[i], str[be]);
		//again swap the char at [i] and [be]
		//this will restore the changes 
	}
}
int main() {
	char str[100];
	cin >> str;
	//input char array
	Permuatation(str, 0);
	//function call
	return 0;
}