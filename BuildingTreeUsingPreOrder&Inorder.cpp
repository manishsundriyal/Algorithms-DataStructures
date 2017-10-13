#include <iostream>
#include <queue>
using namespace std;
class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int value){
		data=value;
		left=NULL;
		right=NULL;
	}
};
int search(int arr[],int start,int end,int x){
	for(int i=start;i<=end;++i){
		if(arr[i]==x) return i;
	}
	return -1;
}
int index=0;
Node* buildBT(int inOrder[],int preOrder[],int start,int end){

	if(start>end) return NULL;
	Node* root=new Node(preOrder[index]);
	++index;
	int pos=search(inOrder,start,end,root->data);
	root->left=buildBT(inOrder,preOrder,start,pos-1);
	root->right=buildBT(inOrder,preOrder,pos+1,end);
	return root;
}
void PrintBT(Node* root){
	if(root==NULL) return;

	
	PrintBT(root->left);
	cout<<root->data<<" ";
	PrintBT(root->right);
}
void inputArray(int arr[],int size){
	for(int i=0;i<size;++i) cin>>arr[i];
}
int main(){
	int size1,size2;
	cin>>size1;
	int *preOrder= new int[size1];
	inputArray(preOrder,size1);
	cin>>size2;
	int *inOrder= new int[size2];
	inputArray(inOrder,size2);

	Node* root=buildBT(inOrder,preOrder,0,size1-1);
	PrintBT(root);
	return 0;
}