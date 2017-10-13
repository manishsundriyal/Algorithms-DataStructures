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
Node* CreateBTLevelWise(){
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
void PrintArray(Node* arr[],int be,int end){
	for(int i=be;i<=end;++i){
		cout<<arr[i]->data<<" ";
	}
	cout<<endl;
}

Node* arr[100];
void PrintAllPaths(Node* root,int index){
	if(root==NULL) return;

	if(root->left==NULL&&root->right==NULL){
		arr[index]=root;
		PrintArray(arr,0,index);
		return;
	}
	arr[index]=root;
	PrintAllPaths(root->left,index+1);
	PrintAllPaths(root->right,index+1);
}
int main(){
	Node* root=CreateBTLevelWise();
	PrintAllPaths(root,0);
	//PrintBTLevelWise(root);		
	return 0;
}