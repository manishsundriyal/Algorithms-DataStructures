#include <iostream>
using namespace std;
class Node{
public:
	int data;
	Node* next;
	Node(int value){
		data=value;
		next=NULL;
	}
};
Node* TakeInput(){
	int size;
	cin>>size;
	Node* head=NULL;
	Node* tail=NULL;
	while(size--){
		
		int num;
		cin>>num;
		Node* newNode=new Node(num);

		if(head==NULL) head=tail=newNode;
		else{
			tail->next=newNode;
			tail=newNode;
		}
	}
	return head;
}
void IterativeReverseLL(Node* &head){
	Node* pre=NULL;
	Node* cur=head;
	Node* ahead;
	while(cur!=NULL){
		ahead=cur->next;
		cur->next=pre;
		pre=cur;
		cur=ahead;
	}
	head=pre;
}
Node* RecursiveReverseLL(Node* head){
	if(head==NULL||head->next==NULL) return head;

	Node* newNode=RecursiveReverseLL(head->next);
	head->next->next=head;
	head->next=NULL;
	return newNode;
}
void printLL(Node* head){
	Node* ptr=head;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}
int main(){
	Node* head=TakeInput();	
	printLL(head);
	IterativeReverseLL(head);
	printLL(head);
	head=RecursiveReverseLL(head);
	printLL(head);
	return 0;
}
//Time Complexity=O(n)
