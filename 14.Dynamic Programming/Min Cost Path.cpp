/*
  You can only traverse down, right and diagonally lower cells from a given cell, i.e., 
  from a given cell (i, j), cells (i+1, j), (i, j+1), and (i+1, j+1) can be traversed. 
  Start from (0,0) --> go till (n-1,n-1) and find minCost Path
  Use DP
  T.C & S.C-O(n^2)
*/
int minPath(vector<vector<int>>&grid,int n){

    int dp[n][n];
    fo(i,n){
        fo(j,n){
            dp[i][j]=0;
        }
    }

    dp[0][0]=grid[0][0];
    //setting 1st row and all col
    for(int i=1;i<n;i++){
        dp[0][i]=dp[0][i-1]+grid[0][i];
    }

    //setting 1st col and all row
     for(int j=1;j<n;j++){
        dp[j][0]=dp[j-1][0]+grid[j][0];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=grid[i][j]+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        }
    }
    return dp[n-1][n-1];
}
