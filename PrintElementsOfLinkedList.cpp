#include <iostream>
using namespace std;
class Node {
public:
	int data;
	//data part of the node
	Node *next;
	// pointer part of the node
	Node(int value) {
		//intialisation take place
		//in this contructor whenenever
		//new node is cerated
		data = value;
		next = NULL;
	}
};
void AddToEnd(Node* &head, Node *newNode) {
	if (head == NULL) {
		//if there is no node in the linked list
		//add the new node after the head node
		head = newNode;
		return;
	}
	//else add the new node to the end of the linked list
	Node *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
		//traversing till the end of the linked list
	}
	//new node is added to the last node of the
	// linked list
	temp->next = newNode;
}
Node *takeInput(int size) {
	//create and initialize head node to NULL
	Node *head = NULL;
	while (size--) {
		int data;
		cin >> data;
		//data of the node
		Node *newNode = new Node(data);
		//creation of a new node
		AddToEnd(head, newNode);
		// addtoend(head,newnode) will add new node the
		// end of the linked list
	}
	return head;
}
void print(Node *head) {
	//printing of all the elements of the linked list
	Node *temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}
int main() {
	int size;
	cin >> size;
	//size of the linked list;
	Node *head = takeInput(size);
	//created a head node and
	//assign the address of next node
	print(head);
	return 0;
}
/*Time Complexity:O(N);
	N is the size of the linked list.
Advantages of Linked List:
1. Dynamic Data Structure(can grow of shrink at runtime)
2. Insertion and Deletion is Easy
Disadvantages of Linked List:
1. Memory Usage
2. Traversal
*/
