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
Node* insertBST(Node* root,int x){
	if(root==NULL){
		Node* newNode=new Node(x);
		return newNode;
	}
	if(x<root->data){
		root->left=insertBST(root->left,x);
	}
	else{
		root->right=insertBST(root->right,x);
	}
	return root;
}
Node* buildBST(){
	int num;
	Node* root=NULL;
	while(true){
		cin>>num;
		if(num==-1) break;
		root=insertBST(root,num);
	}
	return root;
}
void PrintBSTLevelWise(Node* root){
	if(root==NULL) return;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node* curNode=q.front();
		q.pop();
		if(curNode==NULL){
			cout<<endl;
			if(!q.empty()) q.push(NULL);
			continue;
		}
		cout<<curNode->data<<" ";
		if(curNode->left) q.push(curNode->left);
		if(curNode->right) q.push(curNode->right);
	}
}
int main(){
	Node* root=buildBST();
	PrintBSTLevelWise(root);
	return 0;
}