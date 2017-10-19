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
bool IsIdentical(Node* root1,Node* root2){
	if(root1==NULL&&root2==NULL) return true;

	if(root1==NULL||root2==NULL) return false;

	return (root1->data==root2->data)&&
		IsIdentical(root1->left,root2->left)&&
		IsIdentical(root1->right,root2->right);
}
int main(){
	Node* root1=CreateBTLevelWise();
	Node* root2=CreateBTLevelWise();
	cout<<boolalpha<<IsIdentical(root1,root2);	
	return 0;
}