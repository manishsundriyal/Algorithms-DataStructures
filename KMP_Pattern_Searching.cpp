#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;
void computeLPS(string pat,int patLen,int lps[]){

	int len=0;
	lps[0]=0;
	int i=1;

	while(i<patLen){
		if(pat[i]==pat[len]){
			++len;
			lps[i]=len;
			++i;
		}
		else{

			if(len!=0) len=lps[len-1];

			else{
				lps[i]=0;
				++i;
			}
		}
	}
}
void KMP(string text,string pat){

	int txtLen=text.size();
	int patLen=pat.size();

	int lps[patLen];

	computeLPS(pat,patLen,lps);

	int i=0;
	int j=0;
	while(i<txtLen){

		if(pat[j]==text[i]){
			++i;
			++j;
		}
		if(j==patLen){
			cout<<"Pattern Found at "<<i-j<<endl;
			j=lps[j-1];
		}
		else if(i<txtLen&&pat[j]!=text[i]){

			if(j!=0) j=lps[j-1];
			else ++i;
		}
	}
}
int main(){
	string text;
	getline(cin,text);
	string pat;
	getline(cin,pat);
	KMP(text,pat);
	return 0;
}
/*Time Complexity:O(n+m) 
Space Complexity: O(m)*/