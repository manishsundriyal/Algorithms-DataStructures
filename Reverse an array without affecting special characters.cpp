#include <iostream>
using namespace std;
bool isAlpha(char ch){
	return (ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z');
	//compares with the ASCII values and determines
	// if it's a alphabet or not 
}
void Reverse(string &str){
	int left=0;
	//left marker
	int right=str.size()-1;
	//right marker
	while(left<right){
		if(!isAlpha(str[left])) ++left;
		//if str[left] is not an alphabet,
		//then increase the left marker
		else if(!isAlpha(str[right])) --right;
		//if str[right] is not an alphabet,
		//then decrease the right marker
		else{
			swap(str[left],str[right]);
			++left;
			--right;
			//else both of them are an alphabet
			//so, swap them
		}
	}
}
int main(){
	string str;
	cin>>str;
	//input string
	Reverse(str);
	//fucntion call
	cout<<str;	
	return 0;
}
/*Time Complexity: O(N) 
Space Complexity: O(1) */