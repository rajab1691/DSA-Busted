/*
  Input:  nums = [10,9,2,5,3,7,101,18]
  Output: 4
*/
/*
  Recursion
  1. Initially take a variable prev set to INT_MIN
  2. put a ptr to idx=0
  3. Now we have to options
      a. if arr[ptr]>prev
          1.either pick it (if you pick it update ur prev and move ur ptr 1 step)
          2.don't pick it (just move ptr 1 step)
         and set ur ans to max(op1,op2)
      
      b. if arr[ptr]<prev
         1. don't pick it move on
  
  T.C-O(2^n)
  S.C-O(1)
  
*/
int lis(int idx,vector<int>&nums,int prev){

    int n=nums.size();

    if(idx>=n){
        return 0;
    }

    int dontTake=lis(idx+1,nums,prev);
    int take=0;
    
    if(nums[idx]>prev)
      take=1+lis(idx+1,nums,nums[idx]);
  
    return max(dontTake,take);
}

int lengthOfLIS(vector<int>& nums) {
    
    int n=nums.size();

    return lis(0,nums,INT_MIN);   
}


/*
  Recursion+Memoization
 
  T.C-O(n^2)
  S.C-O(n)
*/

vector<int>dp;
int lis(vector<int>&nums,int i,int j){

    int n=nums.size();

    if(i>=n){
        return 0;
    }

    if(dp[j+1]!=-1){
       return dp[j+1];
    }
    
    int dontTake=lis(nums,i+1,j);
    int take=0;
    if(j==-1 or nums[i]>nums[j]){
        take=1+lis(nums,i+1,i);
    }
    return dp[j+1]=max(take,dontTake);
}

int lengthOfLIS(vector<int>& nums) {
    
    int n=nums.size();

    dp.resize(n+1,-1);  

    return lis(nums,0,-1);   
}

/*
  Bottom Up
  T.C-O(n^2)
  S.C-O(n)
*/
int lengthOfLIS(vector < int > & nums) {

  int n = nums.size();
  int ans = 1;
  //initially at least for every one elem ans=1 so put 1 in dp
  vector < int > dp(n, 1);

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      //if curr is greater than prev
      if (nums[i] > nums[j]) {
        //two choice either pick curr with all prev,or just pick right now curr
        dp[i] = max(dp[i], 1 + dp[j]);
        ans = max(ans, dp[i]);
      }
    }
  }
  return ans;
}


/*
  Using Binary Search 
  T.C-O(nlogn)
*/
