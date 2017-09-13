#include <iostream>
using namespace std;
void PrintSubseq(char str[],int be,char output[],int i){

	if(str[be]=='\0'){
		output[i]='\0';
		cout<<output<<endl;
		return;
	}
	PrintSubseq(str,be+1,output,i);
	output[i]=str[be];
	PrintSubseq(str,be+1,output,i+1);
}
int main(){
	char str[100];
	cin>>str;

	char output[100]="";

	PrintSubseq(str,0,output,0);
	return 0;
}