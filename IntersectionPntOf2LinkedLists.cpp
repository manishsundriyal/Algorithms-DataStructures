#include <iostream>
#include <cmath>
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
		Node* newNode= new Node(num);
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
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
}
int FindIntersectionPoint(Node* head1,Node* head2){
	Node* ptr1=head1;
    Node* ptr2=head2;
    int count1=0,count2=0;
    while(ptr1!=NULL){
        ++count1;
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        ++count2;
        ptr2=ptr2->next;
    }
    int diff=abs(count1-count2);

    ptr1=head1,ptr2=head2;
    if(count1>count2){
        while(diff--){
            ptr1=ptr1->next;
        }
    }
    else if(count1<count2){
        while(diff--){
            ptr2=ptr2->next;
        }
    }
    
    while(ptr1!=NULL&&ptr2!=NULL){
        if(ptr1->data==ptr2->data) return ptr1->data;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}
int main(){
	Node* head1=TakeInput();
	Node* head2=TakeInput();
	cout<<FindIntersectionPoint(head1,head2)<<endl;
	return 0;
}