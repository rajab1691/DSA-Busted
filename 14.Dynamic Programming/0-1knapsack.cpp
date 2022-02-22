/*
   int val[] = { 60, 100, 120 };
   int wt[] = { 10, 20, 30 };
   int cap = 50;
   
   o/p: 220
*/

/*
  Recursion
  1. check the last element if wt of last element is greater than capacity then leave it
  2. otherwise to maximize the ans we have to choice max(take it, leave it)
  T.C-O(2^n)
*/

int knapSack(int cap, int wt[], int val[], int n)
{
 
    // Base Case
    if (n == 0 || cap == 0)
        return 0;
  
    if (wt[n - 1] > cap)
        return knapSack(cap, wt, val, n - 1);
 
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            val[n - 1]
                + knapSack(cap - wt[n - 1],
                           wt, val, n - 1),
            knapSack(cap, wt, val, n - 1));
}

/*
  Using Recursion+Memoization
  T.C-O(n*cap)
*/
int dp[100][100];

int knap(int *val,int *wt,int cap,int n){

    if(cap==0 or n==0){
        return 0;
    }

    if(dp[n-1][cap]!=-1){
        return dp[n-1][cap];
    }

    if(wt[n-1]>cap){
        return dp[n-1][cap]=knap(val,wt,cap,n-1);
    }else{
        return dp[n-1][cap]=max(val[n-1]+knap(val,wt,cap-wt[n-1],n-1),
                            knap(val,wt,cap,n-1));
    }
    return dp[n-1][cap];
}

/*
  Using Bottom Up
*/
int knap(int *val,int *wt,int cap,int n){

    int dp[n+1][cap+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=cap;j++){
            if(i==0 or j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=cap;j++){

            if(wt[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
        }
    }
    return dp[n][cap];

}
