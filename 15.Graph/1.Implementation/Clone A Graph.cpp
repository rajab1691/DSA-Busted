/*
  1. use hashmap to make connection b/w original and clone graph
  2. traverse original graph using BFS and make connection b/w cloned and original
  T.C-O(V+E)
*/
Node * cloneGraph(Node * node) {

 unordered_map<Node*,Node*>mp;
  if (node == NULL)
    return NULL;

  Node * copy = new Node(node -> val, {});
  mp[node] = copy;

  queue < Node * > q;
  q.push(node);

  while (!q.empty()) {

    Node * curr = q.front();
    q.pop();
    for (auto x: curr -> neighbors) {
      if (mp.find(x) == mp.end()) {
        mp[x] = new Node(x -> val, {});
        q.push(x);
      }
      mp[curr] -> neighbors.push_back(mp[x]);
    }
  }
  return mp[node];
}
