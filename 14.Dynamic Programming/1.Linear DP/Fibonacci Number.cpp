/*
  Fibonacci Number: 0 1 1 2 3 5 8 13...
  Recurrence Relation: f(n)=f(n-1)+f(n-2)
*/

/*
  1.Using Memoization
  T.C & S.C-O(n)
*/
int fibUsingMemo(int n, vector < int > & dp) {

  if (n <= 1)
    return n;

  if (dp[n] != -1)
    return dp[n];

  return dp[n] = fibUsingMemo(n - 1, dp) + fibUsingMemo(n - 2, dp);

}

/*
  2.Using Tabulation
  T.C & S.C-O(n)
*/
int fibUsingTabu(int n) {
  
  if (n <= 1)
    return n;
  vector<int>dp(n+1,-1);

  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 2] + dp[i - 1];
  }
  return dp[n];
}

/*
  3.Using Space Optimized Approach
  T.C-O(n)
  S.C-O(1)
*/
int fibUsingSpaceOpt(int n) {
  
  if (n <= 1)
    return n;
  
  int prev2 = 0;
  int prev1 = 1;
  int curr;
  for (int i = 2; i <= n; i++) {
    curr = prev1 + prev2;
    prev2 = prev1;
    prev1 = curr;
  }
  return curr;
  
}






