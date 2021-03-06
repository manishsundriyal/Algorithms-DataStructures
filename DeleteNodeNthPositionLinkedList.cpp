#include <iostream>
using namespace std;
class Node{
public:
	int data;
	//data value part of the linked list
	Node* next;
	//pointer part of the linked list
	Node(int num){
		//constructor to initalise values 
		//to the linked list
		data=num;
		next=NULL;
	}
};
void AddToBack(Node *newNode,Node* &head){
	if(head==NULL){
		//if there is no elements in the linked list
		head=newNode;
		return;
	}
	//if there are some elements in the linked list
	Node *ptr=head;
	while(ptr->next!=NULL){
		ptr=ptr->next;
		//take the pointer to the last element of the linked list
	}
	ptr->next=newNode;
	//new node is added at the end of the linked list
}
Node *takeInput(int n){
	Node *head=NULL;
	while(n--){
		int input;
		cin>>input;
		//data to be added
		Node *newNode=new Node(input);
		//new node created
		AddToBack(newNode,head);
		//add the new node to the end of the linked list
	}
	return head;
}
void print(Node *head){
	Node *ptr=head;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
}
void DelNode(Node* &head,int pos){
	Node *cur=head;
	Node *pre=NULL;
	while(pos--&&cur!=NULL){
		pre=cur;
		cur=cur->next;
	}
	if(pre==NULL){
		head=cur->next;
	}
	else	pre->next=cur->next;
}
int main(){
	int n;
	cin>>n;
	Node *head=takeInput(n);
	print(head);
	int pos;
	cin>>pos;
	DelNode(head,pos);
	print(head);
	return 0;
}