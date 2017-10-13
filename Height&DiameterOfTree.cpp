#include <iostream>
#include <queue>
#include <cmath>
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

		int rightNode;
		cin>>rightNode;
		if(rightNode!=-1){
			curNode->right=new Node(rightNode);
			q.push(curNode->right);
		}
	}
	return root;
}
void PrintBTLevelWise(Node* root){
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
int TreeHeight(Node* root){
	if(root==NULL) return 0;
	return max(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}
int TreeDiameter(Node* root){
	if(root==NULL) return 0;

	int curDiameter=TreeHeight(root->left) + 1 + TreeHeight(root->right);
	return max(max(TreeDiameter(root->left),TreeDiameter(root->right)),curDiameter);
}
typedef pair<int,int> ii;
ii TreeDiameterOpt(Node* root){
	if(root==NULL) return ii(0,0);
	ii leftPair=TreeDiameterOpt(root->left);
	ii rightPair=TreeDiameterOpt(root->right);
	int curHeight=max(leftPair.first,rightPair.first)+1;
	int curDiameter=leftPair.first + 1 + rightPair.first;

	ii ans;
	ans.first=curHeight;
	ans.second=max(max(leftPair.second,rightPair.second),curDiameter);
	return ans;
}
bool IsHeightBalanced(Node* root){
	if(root==NULL) return true;

	int LeftHeight=TreeHeight(root->left);
	int rightHeight=TreeHeight(root->right);

	return (abs(LeftHeight-rightHeight)<=1&&IsHeightBalanced(root->left)&&IsHeightBalanced(root->right));
}

typedef pair<int,bool> ib;
ib IsHeightBalancedOpt(Node* root){
	if(root==NULL) return ib(0,true);
	ib leftAns = IsHeightBalancedOpt(root->left);
	ib rightAns = IsHeightBalancedOpt(root->right);
	ib ans;
	ans.first=max(leftAns.first,rightAns.first)+1;
	ans.second=(leftAns.second&&rightAns.second&&abs(leftAns.first- rightAns.first)<=1);
	return ans;
}
int main(){	
	Node* root=CreateBTLevelWise();	
	PrintBTLevelWise(root);

	cout<<"Is Hieight Balanced: "<<boolalpha<<IsHeightBalanced(root)<<endl;
	cout<<"Is Hieight Balanced Optimised: "<<boolalpha<<IsHeightBalancedOpt(root).second<<endl;
	cout<<"Tree Height: "<<TreeHeight(root)<<endl;
	cout<<"Tree Diameter: "<<TreeDiameter(root)<<endl;
	cout<<"Tree Diameter Optimised: "<<TreeDiameterOpt(root).second<<endl;
	return 0;
}