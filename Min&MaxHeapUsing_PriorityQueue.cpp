#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	maxHeap.push(10);
	maxHeap.push(20);
	maxHeap.push(30);
	maxHeap.push(40);
	cout<<"MaxHeap :"<<endl;
	while(!maxHeap.empty()){
		cout<<maxHeap.top()<<" ";
		maxHeap.pop();
	}
	cout<<endl;
	minHeap.push(2);
	minHeap.push(1);
	minHeap.push(3);
	minHeap.push(4);
	cout<<"MinHeap :"<<endl;
	while(!minHeap.empty()){
		cout<<minHeap.top()<<" ";
		minHeap.pop();
	}
	return 0;
}