/*
  Recursion
  1. if characters matches then increase ans by 1 and call for next indices on both string
  2. if don't matches then cal max(fxn(i+1,j),fxn(i,j+1)
  T.C-O(2^n) worst case when all character mismatch
*/

int lcs(string s1,string s2,int i,int j){

    if(i==s1.length() or j==s2.length()){
        return 0;
    }

    if(s1[i]==s2[j]){
        return 1+lcs(s1,s2,i+1,j+1);
    }

    int ans1=lcs(s1,s2,i+1,j);
    int ans2=lcs(s1,s2,i,j+1);
    return max(ans1,ans2);
}

/*
  Bottom Up
*/
 int longestCommonSubsequence(string s1, string s2) {
   int n = s1.length();
   int m = s2.length();

   int dp[n + 1][m + 1];
   for (int i = 0; i <= n; i++) {
     for (int j = 0; j <= m; j++) {
       dp[i][j] = 0;
     }
   }
   for (int i = 0; i <= n; i++) {
     for (int j = 0; j <= m; j++) {
       if (i == 0 or j == 0)
         dp[i][j] = 0;

       else if (s1[i - 1] == s2[j - 1]) {
         dp[i][j] = 1 + dp[i - 1][j - 1];
       } else {
         dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
       }
     }
   }
   return dp[n][m];
 }
