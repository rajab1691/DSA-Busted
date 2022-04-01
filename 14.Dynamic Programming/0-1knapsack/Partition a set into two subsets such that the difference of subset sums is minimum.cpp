/*
  arr[]={1,6,11,5}
  o/p: 1  (12-11)
*/

/*
  Recursive
  Two subsets sums are S1 and S2
  res=min(abs(S1-S2))
  S1=totalSum-S2
  S2=S2
  res=min(abs(totalSum-2*s2))
  T.C-(2^n)
*/
int sub(vector<int>&arr,int n,int calSum,int sum){
    if(n==0){
        return abs(sum-2*calSum);
    }
    return min(sub(arr,n-1,calSum+arr[n],sum),sub(arr,n-1,calSum,sum));
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sub(arr,n-1,0,sum);
}


/*
  Tabulation
  T.C & S.C-O(n*sum)
*/
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];
    
    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
    	
    for(int i=0;i<sum+1;i++)dp[0][i]=0;
    for(int i=0;i<n+1;i++)dp[i][0]=1;
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j] or dp[i-1][j-arr[i-1]];
            }
        }
    }
    
    int ans=1e9;
    
    for(int i=0;i<(sum/2)+1;i++){
        if(dp[n][i]==1){
	    ans=min(ans,abs(sum-2*i));
        }
    }
    return ans;
}
