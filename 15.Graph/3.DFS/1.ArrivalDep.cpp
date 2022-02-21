/*
  1. Just maintain a global variable time
  T.C-O(V+E)
*/

void dfsUtil(int src, vector<int>&arrival,
  vector<int>&dep, int &time,
  vector<int>&visit) {

  visit[src] = 1;
  arrival[src] = ++time;

  for (auto x: l[src]) {
    if (visit[x] == 0) {
      dfsUtil(x, arrival, dep, time, visit);
    }
  }
  dep[src] = ++time;
}
void dfs(int src, int v) {
    
  vector<int>arrival(v,-1);
  vector<int>dep(v,-1);
  vector<int>visit(v,0);
  int time = -1;

  for (int i = 0; i <= v; i++)
    if (visit[i] == 0)
      dfsUtil(i, arrival, dep, time, visit);

  for (int i = 0; i <= v; i++) {
    cout << i << " " << arrival[i] << " " << dep[i] << endl;
  }
}
