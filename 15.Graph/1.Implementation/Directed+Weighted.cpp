/*
  1. Using HashMap
*/
class Graph{

    map<string,list<pair<string,int>>>l;

public:

    void addEdge(string x,string y,int weight){
        l[x].push_back({y,weight});
    }
    void printGraph(){

        for(auto x:l){

            string src=x.first;
            cout<<src<<"->";
            list<pair<string,int>>dest=x.second;

            for(auto e:dest){
                cout<<"( "<<e.first<<","<<e.second<<" )";
            }
            cout<<endl;
        }
    }
};
int32_t main() {

    Graph g;

    g.addEdge("a","c",40);
    g.addEdge("c","d",30);
    g.addEdge("d","b",20);
    g.addEdge("b","a",10);

    g.printGraph();
    
}
