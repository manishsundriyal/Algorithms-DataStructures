#include<bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--){
    int n, c;
    cin>>n>>c;
    int arr[n];
    for(int i=0;i<n;++i) {
      cin>>arr[i];
    }
    int sum = accumulate(arr, arr+n, 0);
    if (sum <= c) {
      cout<<"Yes"<<endl;
    } else {
      cout<<"No"<<endl;
    }
  }
  return 0;
}