class Solution {
public:
    int isSub(string &s,string &t,int x,int y,vector<vector<int>>&dp){
        if(x==0 || y==0) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        if(s[x-1]==t[y-1]) return dp[x][y]=1+isSub(s,t,x-1,y-1,dp);
        else return dp[x][y] = max(isSub(s,t,x-1,y,dp),isSub(s,t,x,y-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return isSub(text1,text2,n,m,dp);
    }
};