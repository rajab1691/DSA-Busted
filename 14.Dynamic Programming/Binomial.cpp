/*
  We know C(n,k)=C(n-1,k-1)+C(n-1,k)
  Recursion
*/
int bin(int n,int k){

    if(n<k)
        return 0;
    if(k==0 or k==n){
        return 1;
    }

    return bin(n-1,k-1)+bin(n-1,k);
}

/*
  Bottom Up
   T.C-O(n*k) 
*/
int bin(int n,int k){

    int dp[n+1][k+1];
   
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){

            if(j==0 or j==i){
                dp[i][j]=1;
            }
            else
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }

    return dp[n][k];
}
