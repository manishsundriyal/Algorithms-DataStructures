#include <iostream>
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
Node* InsertInBST(Node* root,int x){

	if(root==NULL){
		Node* newNode=new Node(x);
		return newNode;
	}
	if(x<root->data){
		root->left=InsertInBST(root->left,x);
	}
	else{
		root->right=InsertInBST(root->right,x);
	}
	return root;
}
Node* CreateBST(){
	int num;
	Node* root=NULL;
	while(true){
		cin>>num;
		if(num==-1) break;
		root=InsertInBST(root,num);
	}
	return root;
}
void PrintInRange(Node* root,int k1,int k2){
	if(root==NULL) return;
	if(root->data<k1) PrintInRange(root->right,k1,k2);
	else if(root->data>k2) PrintInRange(root->left,k1,k2);
	else{
		PrintInRange(root->left,k1,k2);
		if(root->data>=k1&&root->data<=k2) cout<<root->data<<" ";
		PrintInRange(root->right,k1,k2);
	}
}
int main(){
	Node* root=CreateBST();	
	int k1,k2;
	cin>>k1>>k2;
	PrintInRange(root,k1,k2);
	return 0;
}