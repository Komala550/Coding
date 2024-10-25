#include<iostream>
using namespace std;
 
void solve(int n, int k, int *a){
   
   for(int person= 1; person<=k; person++){
 
     int last = 0; int len = 0; int ans = 0;
 
     for(int j =0; j<n; j++){
 
         if(a[j] == 0)len++;
         if(a[j] == 1)len = 0;
         if(len>=ans){
              last = j;
              ans = len;
           }
     }
 
     int s = last-ans+1;
     int mid = (s+last)/2;
     a[mid] = 1;
      //cout<<ans<<" "<<s<<" "<<last<<endl;
 
   }
}
 
int main(){
 
  int t; cin>>t;
  while(t--){
    int n; int k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i<n; i++)a[i] = 0;
    solve(n,k,a);
    for(int i = 0; i<n; i++)cout<<a[i];
    cout<<endl;
  }
  
  return 0;
}
