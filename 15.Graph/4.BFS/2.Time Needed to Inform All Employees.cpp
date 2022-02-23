/*
  1. Create a adj list and then Just apply normal bfs in which we count distance level by level.
  ie.. Just find max time required for the information to reach the last children.
  T.C & S.C- O(n)
*/
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>&time) {

  vector<int>adj[n];
  for (int i = 0; i < n; i++) {
    if (manager[i] != -1) {
      adj[i].push_back(manager[i]);
      adj[manager[i]].push_back(i);
    }
  }
  vector<int>visit(n,0);
  vector<int>dist(n,-1);
        
  queue<int>q;
  q.push(headID);
  visit[headID] = 1;
  dist[headID] = 0;

  int ans = 0;

  while (!q.empty()) {

    int size = q.size();
    while (size--) {

      int node = q.front();
      q.pop();

      for (auto x: adj[node]) {
        if (visit[x] == false) {
          q.push(x);
          visit[x] = 1;
          dist[x] = dist[node] + time[node];
          ans = max(ans, dist[x]);
        }
      }
    }
  }
  return ans;
}

