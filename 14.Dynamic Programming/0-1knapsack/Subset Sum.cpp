/*
  I/P: arr[]={3,4,2,1}, sum=5
  O/P: True (3+2=5,4+1=5)
  ie.. Subset exist equal to that sum
*/

/*
  1.At every step we have to choices either pick or don't pick
  a) Pick
      i) Pick if the arr[idx] <=k 
      ii) Don't Pick if the arr[idx]>k
      
  b) Don't Pick
  
  **0-1 Knapsack
*/

/*
  Recursion+Memoization
  T.C & S.C- O(n*k)
*/
//n =n in this
bool sub(vector<int>&arr,int k,int n,vector<vector<int>>&dp){
    
    if(n==0 and k==0)return true;
    if(n==0)return false;
    if(k==0)return true;
    
    if(dp[n-1][k-1]!=-1)
        return dp[n-1][k-1];
  
    //Don't Pick
    if(arr[n-1]>k){
        return dp[n-1][k-1]=sub(arr,k,n-1,dp);
    }else{
        return dp[n-1][k-1]=sub(arr,k-arr[n-1],n-1,dp) or sub(arr,k,n-1,dp);
    }
    return dp[n-1][k-1];
}


/*
  Tabulation
*/
bool subsetSumToK(int n, int k, vector<int> &arr) {
  
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    
    for(int i=0;i<k+1;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<k+1;j++){
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j] or dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][k];
}
