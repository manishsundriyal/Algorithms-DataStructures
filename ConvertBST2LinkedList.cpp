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
		Node* newNode=new  Node(x);
		return newNode;
	}

	if(x<root->data) root->left=InsertInBST(root->left,x);
	else root->right=InsertInBST(root->right,x);

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
typedef pair<Node*, Node*> nn;
nn getSorted(Node* root){

	if(root==NULL) return nn(NULL,NULL);

	nn left=getSorted(root->left);
	nn right=getSorted(root->right);
	nn ans(NULL,NULL);

	if(left.first){
		ans.first=left.first;
		Node* tail=left.second;
		tail->right=root;
		root->left=tail;
	}
	else{
		ans.first=root;
	}

	if(right.first){
		root->right=right.first;
		right.first->left=root;
		ans.second=right.second;
	}
	else ans.second=root;
	return ans;
}
void PrintDLL(Node* head){
	Node* cur=head;
	while(cur!=NULL){
		cout<<"("<<(cur->left?cur->left->data:0)<<")";
		cout<<cur->data;
		cout<<"("<<(cur->right?cur->right->data:0)<<")";
		cout<<"<-->";
		cur=cur->right;
	}
	cout<<"NULL"<<endl;
}
int main(){
	Node* root=CreateBST();
	PrintDLL(getSorted(root).first);
	return 0;
}