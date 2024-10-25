using namespace std;
int dp[100][100];
int bst(int n, int k){
   if(k ==0 || k ==n)return 1;
   if(dp[n][k] != -1)return dp[n][k];
    dp[n][k] =  bst(n-1,k-1) + bst(n-1,k);
    return dp[n][k];
}
// to calculate the binary trees just multiply n! to the number of bst's
int main(){
   int n; cin>>n;
   int a[n];
   for(int i = 0; i<n; i++)cin>>a[i];
   int A = 2*n;
   int B = n;
   for(int i = 0; i<100; i++)for(int j =0; j<100; j++)dp[i][j] = -1;
   cout<<bst(A,B)/(n+1)<<endl;
  return 0;
}
