/*
  1. Just apply BFS(Kahn's algo)
     a. if there is cycle return false
     b. else return true
*/
bool canFinish(int n, vector<vector<int>>& pre) {
        for(int i=0;i<n;i++

  vector<int>adj[n];
  //making adj list
  for (int i = 0; i < pre.size(); i++) {
    adj[pre[i][1]].push_back(pre[i][0]);
  }

  queue<int>q;
  vector<int>indeg(n,0);

  for (int i = 0; i < n; i++) {
    for (auto x: adj[i]) {
      indeg[x]++;
    }
  }

  for (int i = 0; i < n; i++) {
    if (indeg[i] == 0) {
      q.push(i);
    }
  }
  int cnt = 0;
  while (!q.empty()) {

    int node = q.front();
    q.pop();
    cnt++;
    for (auto x: adj[node]) {
      indeg[x]--;
      if (indeg[x] == 0) q.push(x);
    }
  }
  //if cnt and vertices are equal that means no cycle
  return (cnt == n);
}
