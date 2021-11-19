class Solution {
public:
    int minDistance(string w1, string w2) {
        int n=w1.size(),m=w2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 or j==0) dp[i][j]=0;
                else if(w1[i-1]==w2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return n + m - 2 * dp[n][m];
    }
};


class Solution {
public:
    int isSub(string &s,string &t,int x,int y,vector<vector<int>>&dp){
        if(x==0 || y==0) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        if(s[x-1]==t[y-1]) return dp[x][y]=1+isSub(s,t,x-1,y-1,dp);
        else return dp[x][y] = max(isSub(s,t,x-1,y,dp),isSub(s,t,x,y-1,dp));
    }
    int minDistance(string w1, string w2) {
        int n=w1.length();
        int m=w2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return n + m - 2 * isSub(w1,w2,n,m,dp);
    }
};