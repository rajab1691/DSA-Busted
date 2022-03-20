//https://leetcode.com/problems/jump-game-ii/

/*
  Fibonacci Pattern with little tweaks
  
  1.For every index go forward its array value and fill the value
  2.In dp array take minimum out of them.
  
  T.C & S.C-O(n)
*/

int jump(vector<int>& nums) {
   int n = nums.size();

   if (n == 1)
     return 0;

   vector < int > dp(n, INT_MAX - 2);

   dp[0] = 0;
   dp[1] = 1;

   for (int i = 0; i < n; i++) {
     for (int j = i + 1; j < min(n, i + nums[i] + 1); j++) {
       int val = 1 + dp[i];
       dp[j] = min(dp[j], val);
     }
   }

   return dp[n - 1];
 }
