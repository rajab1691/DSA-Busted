/*
  1. Here change in the quesn is we can not take just one step in 8 direcns but all step till cell is valid
 
  T.C-O(R*C*8*len(str))
*/
bool dfs(int x,int y,int idx,vector<vector<char>>grid, string word){

  int n = grid.size();
  int m = grid[0].size();

  if (idx == word.size()) {
    return true;
  }

  if (x < 0 or x > n - 1 or y < 0 or y > m - 1 or word[idx] != grid[x][y])
    return false;

  char ch = grid[x][y];
  grid[x][y] = '*';
  bool f = false;
  int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
  int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

  for (int i = 0; i < 8; i++) {
    int k, nx = x + dx[i], ny = y + dy[i];

    // First character is already checked,
    // match remaining characters,bcuz word can be found at any point
    for (k = 1; k < word.size(); k++) {
      // If out of bound break
      if (nx >= n || nx < 0 || ny>= m || ny < 0)
        break;

      // If not matched, break
      if (grid[nx][ny] != word[k])
        break;

      // Moving in particular direction
      nx+= dx[i];
      ny+= dy[i];
    }

    // If all character matched,
    // then value of must
    // be equal to length of word
    if (k == word.size())
      return true;
  }
  grid[x][y] = ch;
  return f;

}
vector<vector<int>>searchWord(vector<vector<char>>grid, string word){

  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>>res;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vector < int > ans;
      if (dfs(i, j, 0, grid, word)) {
        ans.push_back(i);
        ans.push_back(j);
        res.push_back(ans);
      }
    }
  }

  return res;
}
