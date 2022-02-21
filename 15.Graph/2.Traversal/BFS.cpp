/*
  1. Use queue to store nodes
  2. everytime visit to its adj nodes check if it already visited 
  3. if it is visited leave else push it into queue & mark it as visited
  
  T.C-O(V+E)
*/
void bfs(int src){

        queue<int>q;
        q.push(src);
        //number of nodes
        int n=l.size();

        vector<bool>visit(n,false);
        visit[src]=true;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            cout<<node<<" ";

            for(auto x:l[node]){
                if(visit[x]==false){
                    q.push(x);
                    visit[x]=true;
                }
            }
        }
    }
