/*
  Topological Sort: means ordering with the help of dependency.
  a.Graph must be DAG
  b.If it's cyclic then everyone will depends upon each other so no topo sort in that case
*/

/*
  1.Use DFS
  => Just do normal DFS, and store it in reverse manner
  T.C-O(V+E)
*/
void topo(int src,vector<int>adj[],vector<bool>&visit,list<int>&order){

    visit[src]=true;

    for(auto x:adj[src]){
        if(visit[x]==false){
            topo(x,adj,visit);
        }
    }
    order.push_front(src);
}
void dfs(vector<int>adj[]){

    vector<bool>visit(v+1,false);

    list<int>order;

    for(int i=0;i<v;i++){
        if(visit[i]==false){
            topo(i,adj,visit,order);
        }
    }
    //this is topo order
    for(auto x:order){
        cout<<x<<" ";
    }
}

/*
   2.Use BFS (Kahn's algo)
      a. Store indegree of all vertices.
      b. if indegre=0,push into queue.
      c. for every adj element reduce indeg by 1 
      d. if indeg=0, push into queue
   T.C-O(V+E)
*/
void topo(){

    vector<int>indeg(v+1,0);

    for(int i=0;i<v;i++){
        for(auto x:adj[i]){
            indeg[x]++;
        }
    }

    queue<int>q;

    for(int i=0;i<v;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){

        int node=q.front();
        q.pop();
        //printing topo order
        cout<<node<<" ";

        for(auto x:adj[node]){
            indeg[x]--;
            if(indeg[x]==0){
                q.push(x);
            }
        }
    }
}
