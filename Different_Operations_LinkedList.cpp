#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int value) {
		data = value;
		next = NULL;
	}
};
Node* takeInput() {
	int n;
	cin >> n;
	Node* head = NULL;
	Node* tail = NULL;
	while (n--) {
		int ele;
		cin >> ele;
		Node* newNode = new Node(ele);

		if (head == NULL) head = tail = newNode;

		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	return head;
}
void PrintLL(Node* head) {
	Node* ptr = head;
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}
void DeleteNthNode(Node* &head, int position) {
	Node* curNode = head;
	Node* pre = head;
	if (position == 0) head = head->next;
	else {
		while (position--) {
			pre = curNode;
			curNode = curNode->next;
		}
		pre->next = curNode->next;
	}
}
void AddAtNthNode(Node* &head, int position) {
	int AddNewValue;
	cin >> AddNewValue;
	Node* newNode = new Node(AddNewValue);
	Node* cur = head;
	Node* pre = head;
	if (position == 0) {
		newNode->next = head;
		head = newNode;
	}
	else {
		while (position--) {
			pre = cur;
			cur = cur->next;
		}
		pre->next = newNode;
		newNode->next = cur;
	}
}
int FindMidNode(Node* head) {
	Node* fast = head;
	Node* slow = head;
	while (slow && fast && fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}
int main() {
	Node* head = takeInput();
	PrintLL(head);
	int deletePosition;
	cin >> deletePosition;
	//Nodes start from 0... 1... 2... 3... and so on
	DeleteNthNode(head, deletePosition);
	PrintLL(head);
	int addPosition;
	cin >> addPosition;
	AddAtNthNode(head, addPosition);
	PrintLL(head);
	cout << FindMidNode(head) << endl;
	return 0;
}