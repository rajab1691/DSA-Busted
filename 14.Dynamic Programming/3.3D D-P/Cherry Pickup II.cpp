// https://leetcode.com/problems/cherry-pickup-ii/

/*
   Memoization
   T.C-O(n*m*m)*9
*/

int cherry(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
  int n = grid.size();
  int m = grid[0].size();

  //boundary condition
  if (j1 < 0 or j2 < 0 or j1 > m - 1 or j2 > m - 1) return -1e8;

  //last row, base condn
  if (i == n - 1) {
    //rob-1 and rob-2 both goes to same column then add only once else add both
    if (j1 == j2) {
      return grid[i][j1];
    } else {
      return grid[i][j1] + grid[i][j2];
    }
  }

  if (dp[i][j1][j2] != -1)
    return dp[i][j1][j2];

  int maxi = -1e8;

  for (int dj1 = -1; dj1 < 2; dj1++) {
    for (int dj2 = -1; dj2 < 2; dj2++) {
      int val = 0;
      //rob-1 and rob-2 both goes to same column then add only once else add both
      if (j1 == j2) {
        val = grid[i][j1];
      } else {
        val = grid[i][j1] + grid[i][j2];
      }
      //explore
      val += cherry(i + 1, j1 + dj1, j2 + dj2, grid, dp);
      maxi = max(maxi, val);
    }
  }
  return dp[i][j1][j2] = maxi;
}
int cherryPickup(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();

   vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));

  int i = 0;
  int j1 = 0, j2 = m - 1;

  return cherry(i, j1, j2, grid, dp);
}

/*
  Tabulation
*/
int cherryPickup(vector<vector<int>>& grid) {

  int n = grid.size();
  int m = grid[0].size();

  vector<int>dir={-1,0,1};

  vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));

  int col1 = 0, col2 = m - 1;

  dp[0][col1][col2] = grid[0][col1] + grid[0][col2];

  int maxi = grid[0][col1] + grid[0][col2];

  for (int i = 1; i < n; i++) {
    for (int c1 = 0; c1 < m; c1++) {
      for (int c2 = 0; c2 < m; c2++) {
        int prev = dp[i - 1][c1][c2];
        if (prev >= 0) {

          for (auto x: dir) {
            col1 = x + c1;
            for (auto y: dir) {
              col2 = y + c2;

              if (col1 >= 0 and col1 <= m - 1 and col2 >= 0 and col2 <= m - 1) {
                dp[i][col1][col2] = max(dp[i][col1][col2], prev + (col1 == col2 ? grid[i][col1] : grid[i][col1] + grid[i][col2]));
                maxi = max(maxi, dp[i][col1][col2]);
              }
            }
          }
        }
      }
    }
  }
  return maxi;
}
