/*
  Greedy Algo(It builds spanning tree by adding edges one by one)
  ->Sort the graph(wrt weights)
  ->Start adding edges to MST (smallest wt->largest wt)
  ->Only add those edges which don't form cycle
  
  T.C-O(elogv)-Using DSU and Sorting
*/
/*
x-->y, w is weight
  graph[0][0]=weight
  graph[0][1]=x
  graph[0][2]=y
*/
int kruskal(vector<vector<int>>graph,int v){

    //sort the graph a/c to weight
    sort(graph.begin(),graph.end());


    DSU s(v);
    
    int cost=0;

    for(auto x:graph){
        int wt=x[0];
        int src=x[1];
        int dest=x[2];

        //if uniting will not make a cycle
        if(s.find(src)!=s.find(dest)){
            s.unite(src,dest);
            cost+=wt;
        }
    }
    return cost;
}
