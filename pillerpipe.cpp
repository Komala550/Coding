#include<iostream>
using namespace std;
#define temp 1000
int dp[51][2002];
bool visited[51][2002];
int a[50],n;
int solve(int index, int sum){
    if(visited[index][sum + temp])
      return dp[index][sum + temp];
      visited[index][sum + temp] = true;
     int &ans = dp[index][sum + temp]; 
      ans = -temp;
      if(index == n){
          if(sum == 0)ans = 0;
      }
      else{
          int x = max(ans , a[index] + solve(index + 1, sum + a[index]));
          int y = max(ans , 0        + solve(index + 1, sum - a[index]));
          int z = max(ans , 0        + solve(index + 1, sum));
          ans = max(x,max(y,z));
      }
      return ans;
}
int main(){
    cin>>n;
    for(int i = 0; i<n; i++)cin>>a[i];
    if(solve(0,0) <= 0)
      cout<<0<<endl;
    else 
      cout<<solve(0,0)<<endl;
    return 0;
}
