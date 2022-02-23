/*
  1. the problem is you just need to find the nodes which are not in cycle
  2. graph is directed, so find cycle in directed graph
  3. whichever node is in cycle make it false
  4. return whichever is true as our safe node
  
  T.C-O(V+E)
*/
 bool dfs(int src,vector<vector<int>>& graph,vector<bool>&visit,vector<bool>&recStack,vector<bool>&safe){

   visit[src] = true;
   recStack[src] = true;

   for (auto x: graph[src]) {

     if (recStack[x] == true) {
       return safe[src] = false;
     }

     if (visit[x] == false) {
       bool f = dfs(x, graph, visit, recStack, safe);
       if (f == false) {
         return safe[src] = false;
       }
     }
   }
   recStack[src] = false;
   return safe[src];
 }
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

   int n = graph.size();
   vector < int > ans;

    vector<bool>visit(n,false);
    vector<bool>recStack(n,false);
    vector<bool>safe(n,true);

   for (int i = 0; i < n; i++) {
     if (visit[i] == false) {
       dfs(i, graph, visit, recStack, safe);
     }
   }

   for (int i = 0; i < n; i++) {
     if (safe[i]) {
       ans.push_back(i);
     }
   }
   return ans;
 }
