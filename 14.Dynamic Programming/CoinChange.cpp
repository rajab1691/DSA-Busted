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
