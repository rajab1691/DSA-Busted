//https://leetcode.com/problems/climbing-stairs/

/*
  1.Same as Fibonacci 
  Recurrence Relation: f(n)=f(n-1)+f(n-2)
  T.C-O(n)
  S.C-O(1)
*/
int climbStairs(int n) {

  if (n <= 3)
    return n;

  int a = 1;
  int b = 2;
  int c;
  for (int i = 3; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}
