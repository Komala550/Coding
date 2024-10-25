 
#include<iostream>
using namespace std;
 
int n,m;
int a[100][100];
int vis[100][100];
 
int dx[] = {-2,-1,1,2,1,-1};
int dy[] = {0,1,1,0,-1,-1};
 
bool valid(int r, int c){
  return (r<2*n && r>=0 && c<m && c>=0);
}
 
int sidha(int i, int j){
  if(valid(i-1,j-1) && valid(i-1,j+1) && valid(i+2,j)){
     return (a[i][j] + a[i-1][j-1] + a[i-1][j+1] + a[i+2][j]);
  }
  else return -1;
}
 
int ulta(int i, int j){
   if(valid(i+1,j-1) && valid(i+1,j+1) && valid(i-2,j)){
     return a[i][j] + a[i+1][j-1] + a[i+1][j+1] + a[i-2][j];
  }
  else return -1;
}
 
int dfs(int r, int c, int power){
 
  if(power == 0)return 0;
 
  vis[r][c] = 1;
 
  int ans = 0;
  for(int i = 0; i<6; i++){
 
    int x = r + dx[i];
    int y = c + dy[i];
 
    if(vis[x][y] == 0 && valid(x,y)){
 
      vis[x][y] = 1;
      int temp = dfs(x,y,power -1);  
      vis[x][y] = 0;
 
       ans = max(temp,ans);
 
    }
  }
 
  vis[r][c] = 0;
 
  ans += a[r][c];
  return ans;
}
 
int main(){
   
   cin>>n>>m;
    for(int i = 0; i<2*n;i+=2){
        for(int j =0; j<m; j++){
            if(!(j%2))
            cin>>a[i][j];
            else
            cin>>a[i+1][j];
        }        
    }
 
   int ans = -1;
   for(int i = 0; i<2*n; i++){
     for(int j =0; j<m; j++){
       if(a[i][j] ){
         
         int temp = dfs(i,j,4);
         int temp2 = ulta(i,j);
         int temp3 = sidha(i,j);
         int temp1 = max(temp2, temp3);
         ans = max(max(temp,temp1),ans);
       }
     }
   }
   
    cout<<ans<<endl;
   
  return 0;
}
