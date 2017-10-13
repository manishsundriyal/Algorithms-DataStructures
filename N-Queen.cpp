#include <iostream>
using namespace std;
const int MAX=20;
bool queen(bool queen[][N],0);
int main(){
	int n;
	cin>>n;
	bool board[MAX][MAX]
	//size of the board;
	bool solExist=queen(board,0);
	if(solExist) printBoard(board);
	else cout<<"Not Possible"<<endl;
	return 0;
}