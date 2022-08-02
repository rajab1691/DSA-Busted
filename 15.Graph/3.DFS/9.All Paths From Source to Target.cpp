/*
  Print all paths from given src to dest
*/

/*
  DFS+Backtracking
*/
vector<vector<int>>ans;
void dfs(int src, int dest, vector<int>adj[], vector<int>&path) {
	path.push_back(src);

	if (src == dest) {
		ans.push_back(path);
	}

	for (auto x : adj[src]) {
		dfs(x, dest, adj, path);
	}
	path.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

	int n = graph.size();
	vector<int>adj[n];

	for (int i = 0; i < n; i++) {
		int m = graph[i].size();
		for (int j = 0; j < m; j++) {
			adj[i].push_back(graph[i][j]);
		}
	}
	vector<int>path;

	dfs(0, n - 1, adj, path);
	return ans;
}
