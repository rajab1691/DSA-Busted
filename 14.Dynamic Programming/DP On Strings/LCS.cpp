/*
  Print Longest common subsequence
  https://atcoder.jp/contests/dp/tasks/dp_f
*/

/*
  Recursive
  T.C-O(2^n)
*/

int lcs(string s,int i,string t,int j){

    if(i==s.length() or j==t.length())
        return 0;

    if(s[i]==t[j]){
        return 1+(lcs(s,i+1,t,j+1));
    }else{
        return max(lcs(s,i+1,t,j),lcs(s,i,t,j+1));
    }
}

/*
  Tabulation
  T.C-O(n^2)
*/
void LCS(){

    string s,t;
    cin>>s>>t;
    int n=s.length();
    int m=t.length();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+(dp[i-1][j-1]);
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int i=s.length();
    int j=t.length();

    string ans="";

    while(i>0 and j>0){

        if(s[i-1]==t[j-1]){
            ans+=s[i-1];
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
