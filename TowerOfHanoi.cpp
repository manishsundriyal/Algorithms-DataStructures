#include <iostream>
using namespace std;
void TowerOfHanoi(int No_of_dics,char source,char dest,char help){

	if(No_of_dics==0) return;
	TowerOfHanoi(No_of_dics-1,source,help,dest);
	cout<<"Move disc from "<<source<<" to "<<dest<<endl;
	TowerOfHanoi(No_of_dics-1,help,dest,source);
}
int main(){
	int No_of_dics;
	cin>>No_of_dics;
	char source='S';
	//source stack+
	char dest='D';
	//destinataion
	char help='H';
	//helper
	TowerOfHanoi(No_of_dics,source,dest,help);	
	return 0;
}