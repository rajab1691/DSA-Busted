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
int minCoins(vector<int>&coins, int n, int amount, vector<int>&dp) {

    //Base Case
    if (amount < 0)
        return -1;
    if (amount == 0)
        return 0;

    if (dp[amount] != 0)
        return dp[amount];

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int subProb = minCoins(coins, n, amount - coins[i], dp);

        if (subProb >= 0 and subProb < ans) {
            ans = subProb + 1;
        }
    }
    //given in problem,cannot make combination then return -1
    if (ans == INT_MAX)
        ans = -1;

    return dp[amount] = ans;
}
int coinChange(vector < int > & coins, int amount) {

    int n = coins.size();

    vector<int>dp(amount + 1, 0);

    return minCoins(coins, n, amount, dp);
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
