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
Node* DetectCycle(Node* head){

	Node* fast=head;
	Node* slow=head;
	while(fast&&fast->next&&fast->next->next){
		if(fast->data==slow->data&&slow!=head) return fast;
		fast=fast->next->next;
		slow=slow->next;
	}
	return NULL;
}
void RemoveCycle(Node* &head){

	Node* pnt=DetectCycle(head);
	if(pnt==NULL) return;
	Node* ptr=head;
	while(ptr->next!=pnt->next){
		ptr=ptr->next;
		pnt=pnt->next;
	}
	pnt->next=NULL;
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
	head->next->next->next->next->next=head->next->next;
	RemoveCycle(head);
	printLL(head);	
	return 0;
}