/*
  1.Fibonacci Pattern
  Recurrence Relation: f(n)=min[ f(n-1),f(n-2) ]+cost[n]
  T.C-O(n)
  S.C-O(1)
*/

 int minCostClimbingStairs(vector<int>& cost) {

   int n = cost.size();

   if (n == 2) return min(cost[0], cost[1]);

   int a = cost[0];
   int b = cost[1];
   int c;

   for (int i = 2; i < n; i++) {
     c = min(a, b) + cost[i];
     a = b;
     b = c;
   }

   return min(a, b);
 }
