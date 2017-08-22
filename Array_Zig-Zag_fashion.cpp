#include <iostream>
#include <algorithm>
using namespace std;
void ConvertZigZag(int arr[],int size){
	bool flag=true;
	for(int i=0;i<size-1;++i){
		if(flag){
			if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
		}
		else{
			if(arr[i]<arr[i+1]) swap(arr[i],arr[i+1]);
		}
		flag=!flag;
	}
}
void print(int arr[],int size){
	for(int i=0;i<size;++i) cout<<arr[i]<<" ";
}
int main(){
	int size; cin>>size;
	int arr[size];
	for(int i=0;i<size;++i) cin>>arr[i];
	ConvertZigZag(arr,size);	
	print(arr,size);
	return 0;
}
/*Time Complexity: O(N)
Space Complexity: O(1) */