//https://atcoder.jp/contests/dp/tasks/dp_a

/*
  Fibonacci with little tweak
  Recurrence Relation:
    val1= dp[i-1]+abs(a[i]-a[i-1]) //coming from last stone
    val2= dp[i-2]+abs(a[i]-a[i-2]) //coming from second last stone
    dp[i]=min(val1,val2)
    
    T.C & S.C-O(n)
*/
int cost(int *a,int n){

    vector<int>dp(n+1,INT_MAX);

    dp[1]=0;
    dp[2]=abs(a[1]-a[2]);

    for(int i=3;i<=n;i++){
        int val1=dp[i-1]+abs(a[i]-a[i-1]);
        int val2=dp[i-2]+abs(a[i]-a[i-2]);
        dp[i]=min(val2,val1);
    }

    return dp[n];
}

void solve(){

    int n;cin>>n;

    int a[n+1];

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    cout<<cost(a,n)<<endl;
}
