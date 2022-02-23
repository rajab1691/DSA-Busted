/*
  Just apply dfs whenever you encounter 1 in grid, and take maximum count of 1 in matrix.
  T.C-O(n*m)
*/

int dfs(int x,int y,vector<vector<int>>& grid){
  int n = grid.size();
  int m = grid[0].size();

  if (x < 0 or x > n - 1 or y > m - 1 or y < 0 or grid[x][y] == 0) {
    return 0;
  }
  grid[x][y] = 0;
  int cnt = 1;

 int dx[]={-1,1,0,0};
 int dy[]={0,0,-1,1};

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    cnt += dfs(nx, ny, grid);
  }
  return cnt;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();

  int finalAns = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) {
        int ans = dfs(i, j, grid);
        finalAns = max(ans, finalAns);
      }
    }
  }
  return finalAns;
}
