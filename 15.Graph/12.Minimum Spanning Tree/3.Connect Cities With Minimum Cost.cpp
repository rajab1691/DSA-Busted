/*
  ** Just find MST
  1. Using Kruskal's algo
  
*/

bool cmp(vector<int> const &a, vector<int> const &b)
{
    return a[2] < b[2];
}

int getMinimumCost(int n, int m, vector<vector<int>> &connections)
{
 	int cost=0;
    DSU s(n);
    sort(connections.begin(),connections.end(),cmp);
    
    for(int i=0;i<connections.size();i++){
        int s1=connections[i][0];
        int s2=connections[i][1];
        int wt=connections[i][2];
        if(s.findSet(s1)!=s.findSet(s2)){
            s.unionSet(s1,s2);
            cost+=wt;
        }
    }
    int parentOfAll=s.findSet(1);
    for(int i=2;i<=n;i++){
        if(parentOfAll!=s.findSet(i)){
            return -1;
        }
    }
  	return cost;
}









