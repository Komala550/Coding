#include<bits/stdc++.h>
using namespace std;
int n,c;
int a[100];
int b[100];
int pre[100];
int dp[100][100][2];
void sum(){
    for(int i=1; i<=n; i++)
       pre[i] = a[i] + pre[i-1];
}
int solve(){
   for(int j = 1; j<=n; j++){
       for(int k = 1; k<=c && k<=j; k++){
           if(k == 1){
               dp[j][k][0] =  pre[j];
               dp[j][k][1] =  pre[j];
           }
        
           else{
 
               int temp = INT_MAX;
               for(int l = j; l>k-1; l--){
                    int mn = min((pre[j]-pre[l-1]), min(dp[l-1][k-1][0], dp[l-1][k-1][1]));
                    int mx = max((pre[j]-pre[l-1]), max(dp[l-1][k-1][0], dp[l-1][k-1][1]));
                    
                    if(mx-mn < temp){
                        temp = mx - mn;
                        dp[j][k][0] = mn;
                        dp[j][k][1] = mx;
                    }
            
               }
               
                 
           }
          
       }
   }
   return dp[n][c][1] - dp[n][c][0];
}
 
 
int main(){
    
    int t; cin>>t;
    while(t--){
        cin>>c;
        cin>>n;
        for(int i = 1; i<=n; i++)cin>>b[i];
        for(int i = n+1; i<=2*n; i++)b[i] = b[i-n];
        int ans = INT_MAX;
        for(int i = 1; i<=n+1; i++){
                int j = i+n-1;
                memset(dp,0,sizeof(dp));
                memset(pre, 0, sizeof(pre));
                int temp  = 1;
                for(int k = i; k<=j; k++){
                    a[temp] = b[k];
                    temp++;
                }
                 sum();
                 ans = min(ans, solve());
        }
       if(c>n)ans = -1;
       cout<<ans<<endl;
    }
}
