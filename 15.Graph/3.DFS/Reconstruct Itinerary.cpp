/*
    1. Idea is to use DFS
    2. Create an Adj List
    3. Use multiset,stack 
    T.C-O(ElogE)
*/

vector<string> findItinerary(vector<vector<string>>& tickets) {
      vector<string>res;
      //multiset because we may have more than 1 tickets to the src->dest
    unordered_map<string,multiset<string>>mp;
      //creating adj list
      for (int i = 0; i < tickets.size(); i++) {
        mp[tickets[i][0]].insert(tickets[i][1]);
      }

      stack<string>stack;
      stack.push("JFK");

      while (!stack.empty()) {
        string src = stack.top();
        //when all tickets are covered for that, then push into res            
        if (mp[src].size() == 0) {
          res.push_back(src);
          stack.pop();
        } else {
          auto dest = mp[src].begin();
          stack.push( * dest);
          mp[src].erase(dest);
        }

      }
      reverse(res.begin(), res.end());
      return res;
    }
