//https://atcoder.jp/contests/dp/tasks/dp_b

/*
  Fibonacci Pattern with little tweak
  1.The Idea is to go to each k extra index from each index ie.. we know we can move till [index,index+k]
  2.Take minimum at every indices 
  
  T.C-O(n*k)
  S.C-O(n)
*/

int cost(int * arr, int n, int k) {

  vector < int > dp(n + 1, INT_MAX);

  dp[1] = 0;
  dp[2] = abs(arr[1] - arr[2]);

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j < min(n + 1, i + 1 + k); j++) {
      int val = dp[i] + abs(arr[i] - arr[j]);
      dp[j] = min(dp[j], val);
    }
  }
  return dp[n];
}

void solve() {

  int n, k;
  cin >> n >> k;

  int a[n + 1];

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  cout << cost(a, n, k) << endl;
}
