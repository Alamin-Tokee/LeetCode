//Time Complexity O(n*m)
//Space Complexity O(n*m)
class Solution {
public:
    int numDistinct(string s, string t) {
        unsigned long long i,j,n,m;
        n=s.length();
        m=t.length();
        vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};
//Time Complexity O(n*m)
//Space Complexity O(n*m)
class Solution {
public:
    int dp[1001][1001];
    int solve(string &s, string &t,int i,int j){
        if(j==t.length()) return 1;
        if(i==s.length()) return 0;
        else if(dp[i][j]!=-1) return dp[i][j];
        else if(s[i]==t[j]) re  turn dp[i][j]=solve(s,t,i+1,j+1)+solve(s,t,i+1,j);
        else return dp[i][j]=solve(s,t,i+1,j);
    }
    int numDistinct(string s, string t) {
        
        memset(dp,-1,sizeof(dp));
        
        return solve(s,t,0,0);
    }
};