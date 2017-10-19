#include <iostream>
#include <queue>
#include <climits>
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
Node* CreateBSTLevelWise(){
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
bool IsBST(Node* root,int minVal,int maxVal){
	if(root==NULL) return true;
	return (root->data>=minVal&&root->data<=maxVal)&&
			IsBST(root->left,minVal,root->data)&&
			IsBST(root->right,root->data,maxVal);
}
int main(){
	Node* root=CreateBSTLevelWise();	
	cout<<boolalpha<<IsBST(root,INT_MIN,INT_MAX);
	return 0;
}