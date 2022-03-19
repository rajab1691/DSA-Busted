//https://leetcode.com/problems/n-th-tribonacci-number/

/*
  1.Same approach as Fibonacci number 
  Recurrence Relation: f(n)=f(n-1)+f(n-2)+f(n-3)
  T.C-O(n)
  S.C-O(1)
*/
int tribonacci(int n) {

  if (n <= 1)
    return n;
  if (n == 2)
    return 1;

  int a = 0;
  int b = 1;
  int c = 1;
  int d;
  for (int i = 3; i <= n; i++) {
    d = a + b + c;
    a = b;
    b = c;
    c = d;
  }
  return d;
}
