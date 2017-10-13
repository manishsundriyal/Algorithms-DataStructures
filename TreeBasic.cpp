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
		right=NULL;
		left=NULL;
	}
};
Node* createBT(){
	int num;
	cin>>num;
	if(num==-1) return NULL;
	Node* root=new Node(num);

	root->left=createBT();
	root->right=createBT();
	return root;
}
Node* createBTLevelWise(){
	int num;
	cin>>num;
	if(num==-1) return NULL;

	Node* root=new Node(num);

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){

		Node* curNode=q.front();
		q.pop();

		int leftData;
		cin>>leftData;
		if(leftData!=-1){
			curNode->left=new Node(leftData);
			q.push(curNode->left);
		}

		int rightData;
		cin>>rightData;
		if(rightData!=-1){
			curNode->right=new Node(rightData);
			q.push(curNode->right);
		}
	}
	return root;
}
void PrintPreOrderBT(Node* root){
	if(root==NULL) return;

	cout<<root->data<<" ";
	PrintPreOrderBT(root->left);
	PrintPreOrderBT(root->right);
}
void PrintInOrderBT(Node* root){
	if(root==NULL) return;

	PrintInOrderBT(root->left);
	cout<<root->data<<" ";
	PrintInOrderBT(root->right);
}
void PrintPostOrderBT(Node* root){
	if(root==NULL) return;

	PrintPostOrderBT(root->left);
	PrintPostOrderBT(root->right);
	cout<<root->data<<" ";
}
void PrintLevelWise(Node* root){
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

	// Node* root=createBT();	
	Node* root=createBTLevelWise();
	
	PrintPreOrderBT(root);
	cout<<endl;
	PrintInOrderBT(root);
	cout<<endl;
	PrintPostOrderBT(root);
	cout<<endl;
	PrintLevelWise(root);
	cout<<endl<<cntNodes(root);
	/*
	Test Case:
					1
				   / \
				  /   \
				 2     3
				/ \   / \
			   4   5 6   7  

	Input: 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
	LevelWiseInput: 1
					2 3
					4 5 6 7
					-1 -1 -1 -1 -1 -1 -1 -1

	Pre-Order Output: 1 2 4 5 3 6 7
	In-Order Output: 4 2 5 1 6 3 7
	Post-Order Output: 4 5 2 6 7 3 1
 	*/

	return 0;
}