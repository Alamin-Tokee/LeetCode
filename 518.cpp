class Solution {
public:
    int solve(vector<int> & coins,int amount,int n,vector<vector<int>>&dp){
        if(amount == 0) return 1;
        
        if(n == 0) return 0;
        
        if(dp[amount][n]!=-1) return dp[amount][n];
        
        if(coins[n-1] <= amount){
            return dp[amount][n] = solve(coins, amount-coins[n-1], n, dp)+solve(coins, amount, n-1, dp);
        }else{
            return dp[amount][n] = solve(coins,amount,n-1,dp);
        }
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp (amount+1,vector<int>(coins.size()+1,-1));
        return solve(coins,amount,coins.size(),dp);
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int dp[amount+1][n+1];
        for(int i=0;i<amount+1;i++) dp[i][0]=0;
        for(int i=0;i<n+1;i++) dp[0][i]=1;
        
        for(int i=1;i<amount+1;i++)
            for(int j=1;j<n+1;j++)
            {   if(coins[j-1]<=i)
                    dp[i][j] = dp[i-coins[j-1]][j] + dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        return dp[amount][n];
    }
};