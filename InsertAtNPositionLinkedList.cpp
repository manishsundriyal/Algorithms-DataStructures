#include <iostream>
using namespace std;
//Node class
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
void EnterAtNPosition(Node* &head,int value,int pos){
	Node *newNode=new Node(value);
	//New Node created with data value.
	Node *cur=head;
	Node *pre=NULL;
	//two Nodes one for current Node 
	//other for the previous Node
	while(pos--&&cur!=NULL){
		//while we reach that position
		pre=cur;
		//stores the address of the previous node
		cur=cur->next;
		//stores the address of the next node
	}
	if(pre==NULL){
		//if there are zero elements in the linked list
		newNode->next=head;
		head=newNode;
		//add new node to the head node
	}
	else{
		//there are some elements in the linked list
		pre->next=newNode;
		//preivous node points to the new node 
		newNode->next=cur;
		//and new node now points to the current node
		//hence a new node is added in btw them
	}
}
int main(){
	int n;
	cin>>n;
	//number of elements in the linked list
	Node *head=takeInput(n);
	//takeInput() will add elements to the linked list
	//print the linked list
	print(head);	
	int pos;
	cin>>pos;
	//position at which new element should be added
	int value;
	cin>>value;
	//value of the new element
	EnterAtNPosition(head,value,pos);
	//function call to add new node at pos position
	print(head);
	return 0;
}