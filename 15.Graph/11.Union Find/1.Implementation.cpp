/*

*/

class DSU {

    int *parent;
    int *rank;

public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }

    }
    //Union of two set
    void unite(int u, int v) {

        int s1 = find(u);
        int s2 = find(v);

        if (s1 != s2) {
            if (rank[s2] > rank[s1]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
    //Return the Leader
    int find(int i) {
        if (parent[i] == -1) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

};

int32_t main() {

    DSU s(5);
    s.unite(2, 3);
    s.unite(3, 4);
    cout << s.find(2);
    cout << s.find(4);

}
