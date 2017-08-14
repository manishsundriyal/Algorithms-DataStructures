#include <iostream>
using namespace std;
#define RANGE 200
//max RANGE
void print(int arr[],int size){
	for(int i=0;i<size;++i) cout<<arr[i]<<" ";
    cout<<endl;
}
void CountSort(int arr[],int size){

	int sortedArr[size];
	int count[RANGE+1]={};
	//array declaration, with all the elements defined to zero
	// arr[size+1]={0,0,0,0,0.....upto size+1}
	// same as memset(arr, 0, sizeof(arr));
	for(int i=0;i<size;++i){
		++count[arr[i]];
	}
	//count array stores the occurance frequncy of each element.
	for(int i=1;i<=RANGE;++i){
		count[i]+=count[i-1];
	}
	//modifies the count array by adding up the previous element to the current one.
	for(int i=0;i<size;++i){
		sortedArr[count[arr[i]]-1]=arr[i];
        --count[arr[i]];
	}
	//all the elements are now stored in the sortedArr in sorted manner
	print(sortedArr,size);
}
int main(){
	int size; cin>>size;
	//size of the array
	int arr[size];
	//array declaration
	for(int i=0;i<size;++i) cin>>arr[i];
	//array defination	
	CountSort(arr,size);
	// CountSort Function call.
	return 0;
}