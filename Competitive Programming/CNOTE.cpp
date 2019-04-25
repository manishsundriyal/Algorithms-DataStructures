#include<bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--){
    int x,y,k,n;
    bool isLucky = false;
    cin>>x>>y>>k>>n;
    int pages[n], prices[n];
    for(int i=0;i<n;++i){
      cin>>pages[i]>>prices[i];
    };
    for(int i=0;i<n;++i){
      if(pages[i] + y >= x && prices[i] <= k) {
        isLucky = true;
        break;
      }
    }
    if (isLucky) {
      cout<<"LuckyChef"<<endl;
    } else {
      cout<<"UnluckyChef"<<endl;
    }
  }
  return 0;
}