class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0) return true;
        int x=s.length(), y=t.length();
        int dp[x+1][y+1];
        
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(i==0 or j==0) dp[i][j]=0;
                else if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[x][y]==x ? true : false;
    }
};


class Solution {
public:
    int isSub(string s,string t,int x,int y,vector<vector<int>>&dp){
        if(x==0 || y==0) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        if(s[x-1]==t[y-1]) return dp[x][y]=1+isSub(s,t,x-1,y-1,dp);
        else return dp[x][y] = max(isSub(s,t,x-1,y,dp),isSub(s,t,x,y-1,dp));
    }
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int len=isSub(s,t,n,m,dp);
        return len==n;
    }
};