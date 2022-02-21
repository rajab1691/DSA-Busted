/*
  1. if all nodes are not visited from room 0 then return false
  3. else return true
  
  T.C-O(V+E)
*/

 void dfs(int src,vector<vector<int>>&rooms,vector<bool>&visit) {

   visit[src] = true;

   for (auto x: rooms[src]) {
     if (visit[x] == false) {
       dfs(x, rooms, visit);
     }
   }
 }
 bool canVisitAllRooms(vector<vector<int>>&rooms) {

   int n = rooms.size();

   vector<bool>visit(n,false);

   dfs(0, rooms, visit);

   for (int i = 0; i < n; i++) {
     if (visit[i] == false) {
       return false;
     }
   }
   return true;
 }
