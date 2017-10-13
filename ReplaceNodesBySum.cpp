#include <iostream>
#include <queue>
using namespace std;
class Node{
public:
	int data;
	Node* right;
	Node* left;
	Node(int value){
		data=value;
		right=NULL;
		left=NULL;
	}
};
Node* CreateBTLevelWise(){
	Node* root=NULL;
	int num;
	cin>>num;
	if(num==-1) return NULL;

	root=new Node(num);

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
void PrintBTLevelWise(Node* root){
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
int ReplaceNodeBySum(Node* root){

	if(root==NULL) return 0;
	
	int left=ReplaceNodeBySum(root->left);
	int right=ReplaceNodeBySum(root->right);
	int curSum=left+right+root->data;
	root->data=left+right;
	return curSum;
}
int main(){
	Node* root=CreateBTLevelWise();	
	ReplaceNodeBySum(root);
	PrintBTLevelWise(root);
	return 0;
}