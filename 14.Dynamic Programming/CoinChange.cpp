/*
  Que: Given an integer array coins, amount is given.
       Find minimum coins need to make up that amount.
       Assume that you have an infinite number of each kind of coin.
  eg: coins = [1,2,5], amount = 11
      11 = 5 + 5 + 1 so o/p:=3
*/
/*
  1. Use Recursion+Memoization
  
  T.C-O(amount*sizeOfArray)
  
*/
 int dp[10000 + 1][12 + 1]; 

 int memoization(vector < int > & wt, int w, int n) {
   if (n == 0 || w == 0)
     return (w == 0) ? 0 : INT_MAX - 1;

   if (dp[w][n] != -1) 
     return dp[w][n]; 

   if (wt[n - 1] > w)
     return dp[w][n] = memoization(wt, w, n - 1);
   else
     return dp[w][n] = min(memoization(wt, w , n - 1), 1 + memoization(wt, w - wt[n - 1], n));
 }

 int coinChange(vector < int > & coins, int amount) {
   memset(dp, -1, sizeof(dp));
   int minCoins = memoization(coins, amount, coins.size());
   return minCoins == INT_MAX - 1 ? -1 : minCoins;
 }

/*
  2. Bottom Up (Tabulation)
  Algo: a.Fill Dp array with maximum value which is amount+1 in this case
        b.start filling dp array considering every coins
        c.return dp[amount]
*/
int coinChange(vector < int > & coins, int amount) {

    vector<int>dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    if (dp[amount] > amount)
        return -1;
    return dp[amount];
}
