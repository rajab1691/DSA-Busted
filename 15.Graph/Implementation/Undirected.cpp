/*
  1.Using HashMap
*/

class Graph{

    map<int,list<int>>l;

public:

    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printGraph(){

        for(auto x:l){
            cout<<x.first<<"->";
            list<int>edges=x.second;

            for(auto e:edges){
                cout<<e<<" ";
            }
            cout<<endl;
        }
    }
};
int32_t main() {

    Graph g;

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);

    g.printGraph();
    
}
