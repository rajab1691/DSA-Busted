//https://leetcode.com/problems/house-robber-ii/

/*
  Same as House robber-1
  1.Just cal max(rob1,rob2)
  2.where rob1=(0,n-1) and rob2=(1,n)
*/

int houseRobber(vector<int>& nums,int idx,int n){

   if (idx >= n - 1)
     return 0;

   vector<int>dp(n,INT_MIN);
   dp[idx] = nums[idx];
   dp[idx + 1] = max(nums[idx], nums[idx + 1]);

   for (int i = idx + 2; i < n; i++) {
     dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
   }
   return dp[n - 1];
 }
 int rob(vector<int>& nums) {
   int n = nums.size();

   if (n == 1)
     return nums[0];
   if (n == 2)
     return max(nums[0], nums[1]);

   return max( houseRobber(nums, 0, n - 1), houseRobber(nums, 1, n));
 }
