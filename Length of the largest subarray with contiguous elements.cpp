#include <iostream>
#include <algorithm>
using namespace std;
int MaxLength(int arr[],int size){
	int len=1;
	//because minimum length
	// of such a contigous array can be one
	int maxE,minE;
 	for(int i=0;i<size-1;++i){
 		minE=arr[i];
 		maxE=arr[i];
 		//makes the inital element as max and min element of the subarray
 		for(int j=i+1;j<size;++j){
 			maxE=max(arr[j],maxE);
 			minE=min(arr[j],minE);
 			//looks of smallest and lagest element in the sub array
 			if(maxE-minE==j-i) len=max(len,maxE-minE+1);
 			//if difference btw largest and smallest
 			//element is equal to the difference
 			//of the index of i and j
 			//then save the +1 of that diff as the len.
 			//that is current subarray is having all contigous subarray
 		}
	}
	return len;
}
int main(){
	int size; cin>>size;
	//size of the array
	int arr[size];
	//array declared
	for(int i=0;i<size;++i) cin>>arr[i];
	//array defined
	cout<<MaxLength(arr,size);	
	//function called
	return 0;
}
/*Time Complexity:O(N^2) 
Space Complexity: O(1)*/