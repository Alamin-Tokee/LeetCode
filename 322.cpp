class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int n=coins.size();
        int t[n+1][sum+1];
        
        for(int i=0;i<sum+1;i++) t[0][i]=INT_MAX-1;
        for(int j=0;j<n+1;j++) t[j][0]=0;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(coins[i-1] <= j){
                    t[i][j]=min(1+t[i][j-coins[i-1]],t[i-1][j]);
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return (t[n][sum] == INT_MAX || t[n][sum] == INT_MAX-1) ? -1 : t[n][sum];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(auto &coinVal : coins){
            for(int i=coinVal;i<amount+1;++i){
                dp[i] = min(dp[i],1+dp[i-coinVal]);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
}; 


class Solution {
public:
// MEMO
    int solve(vector<int>& coins, int w,int n,vector<vector<int>>&memo){
        if(n==0 || w==0){
           return w==0? 0:INT_MAX - 1;
        }
        if(memo[w][n]!=-1) return memo[w][n];
        if(coins[n-1]>w){
            return memo[w][n] = 0 + solve(coins,w,n-1,memo);
        }
        else return memo[w][n] = min(0+solve(coins,w,n-1,memo),1+solve(coins,w-coins[n-1],n,memo));
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>memo(amount+1,vector<int>(n+1,-1));
        int minCoins = solve(coins,amount,coins.size(),memo);
        return minCoins==INT_MAX-1?-1:minCoins;
    }
};