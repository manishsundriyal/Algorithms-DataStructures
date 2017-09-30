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
Node* takeInput(){
	int n;
	cin>>n;
	
	Node* head=NULL;
	Node* tail=NULL;
	while(n--){
		int element;
		cin>>element;
		Node* newNode = new Node(element);

		if(head==NULL) head=tail=newNode;

		else{
			tail->next=newNode;
			tail=newNode;
		}
	}
	return head;
}
void PrintLL(Node* head){
	Node* ptr=head;
	while(ptr!=NULL){
		cout<<ptr->data<<"-->";
		ptr=ptr->next;
	}
	cout<<"NULL"<<endl;
}
int main(){
	Node* head=takeInput();	
	PrintLL(head);	
	return 0;
}
