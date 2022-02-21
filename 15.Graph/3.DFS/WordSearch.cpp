/*
  1. Idea is to apply DFS and go to every 4 direction cell if its matching increase index of word and 
  2. go to next cell
  3. if idx becomes greater than size of word return true
  
  T.C-O(M * N * 4^L)
*/

bool dfs(int x,int y,int idx,vector<vector<char>>& board, string word){
  int n = board.size();
  int m = board[0].size();

  //if idx is greeater than word's length that means word is found
  if (idx == word.size()) {
    return true;
  }
  //if cell is invalid and char's are not matching then return false
  if (x < 0 or y < 0 or x > n - 1 or y > m - 1 or board[x][y] != word[idx])
    return false;

  //take into a char so that after we will set it as it was
  char ch = board[x][y];
  //no cell can be use twice,in one move
  board[x][y] = '*';

  int dx[]={-1,1,0,0};
  int dy[]={0,0,-1,1};
  bool f = false;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    f = dfs(nx, ny, idx + 1, board, word);
    if (f) return true;
  }
  //backtrack,mark the char as it was previously
  board[x][y] = ch;
  return f;
}

bool exist(vector<vector<char>>& board, string word) {

  int n = board.size();
  int m = board[0].size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dfs(i, j, 0, board, word))
        return true;
    }
  }
  return false;
}
