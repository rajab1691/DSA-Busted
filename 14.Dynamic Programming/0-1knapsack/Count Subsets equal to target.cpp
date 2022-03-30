/*
  Same as Subset sum problem
  I/P: arr = {0,0,1}
  O/P: 4 [(1),(0,1),(0,1),(0,0,1)]
  ie.. there may be 0 in the array
*/

/*
  Recursive+Memoization
*/

int findWaysUtil(int n, int target, vector<int>& arr, vector<vector<int>> &dp){

    if(n == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
    }
    
    if(dp[n][target]!=-1)
        return dp[n][target];
        
    int notTaken = findWaysUtil(n-1,target,arr,dp);
    
    int taken = 0;
    if(arr[n]<=target)
        taken = findWaysUtil(n-1,target-arr[n],arr,dp);
        
    return dp[n][target]= notTaken + taken;
}

int findWays(vector<int> &num, int k){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,num,dp);
}
