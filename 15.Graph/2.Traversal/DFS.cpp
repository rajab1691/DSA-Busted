/*  
  T.C-O(V+E)
*/
void dfsUtil(int src, vector<bool>&visit) {

  visit[src] = true;
  cout << src << " ";
  //go to adj for each nodes and check 
  for (auto x: l[src]) {
    if (visit[x] == false) {
      dfsUtil(x, visit);
    }
  }
}
void dfs(int src) {
  //count of nodes
  int n = l.size();
  vector<bool>visit(n, false);

  dfsUtil(src, visit);
}
