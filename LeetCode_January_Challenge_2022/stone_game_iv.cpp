//TC O(n)
//SC O(n)
class Solution {
public:
    bool solve(int n, vector<int>&dp) {
        if(n<=0) return false;
        if(dp[n]!=-1) return dp[n];
        for(int i=1; i*i<=n; i++)
            if(!solve(n-i*i, dp)) return dp[n] = true;
        return dp[n] = false; 
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(100001, -1);
        return solve(n,dp);
    }
};
