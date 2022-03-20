//https://leetcode.com/problems/house-robber/

/*
  0-1 Knapsack, Either take it or leave it
  
  1. If we loot house then we can't loot house next to it
  Recurrence Relation: dp[i]=max(dp[i-1],nums[i]+dp[i-2])
*/
/*
  Using Memoization
  1.At each index we have two choices either take it or leave it
  2.if we take that index elem then add ans + go its next's next house 
  3.else go to its next house
  4.return max of 2nd and 3rd step
  
  T.C & S.C-O(n)
*/
int robbing(vector<int>&nums,int idx,vector<int>&dp){
   int n = nums.size();
   if (idx >= n) return 0;

   if (dp[idx] != -1)
     return dp[idx];

   int take = nums[idx] + robbing(nums, idx + 2, dp);
   int leave = robbing(nums, idx + 1, dp);

   return dp[idx] = max(take, leave);

 }
 int rob(vector<int>& nums) {
   int n = nums.size();
   vector<int>dp(n, -1);
   return robbing(nums, 0, dp);
 }

/*
  Using Tabulation
  
  T.C & S.C-O(n)
*/

int rob(vector<int>& nums) {

  int n = nums.size();
  if (n == 1)
    return nums[0];
  if (n == 2)
    return max(nums[0], nums[1]);

 vector<int>dp(n,INT_MIN);

  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);

  for (int i = 2; i < n; i++) {
    dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
  }
  return dp[n - 1];
}
