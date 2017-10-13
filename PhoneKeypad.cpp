#include <iostream>
using namespace std;
const string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void PhoneKeypadCodes(char str[],int index1,char output[],int index2){

	if(str[index1]=='\0'){
		output[index2]='\0';
		cout<<output<<endl;
		return;
	}
	//base cases

	int digit=str[index1]-'0';
	//converts the current character into integer
	string code=table[digit];
	//code stores the corresponding string for that digit

	for(int i=0;i<code.size();++i){
		output[index2]=code[i];
		//fix the character from the first array and call for the next
		PhoneKeypadCodes(str,index1+1,output,index2+1);
	}
}
int main(){
	char str[100];
	cin>>str;
	//input the array of char
	char output[100];
	//additional char array for storage of result
	PhoneKeypadCodes(str,0,output,0);	
	//function call
	return 0;
}
