class Solution {
public:
    //int dp[1000]={0};
    int climbStairs(int n) {
        //memset(dp,0,sizeof(dp));
        vector<int> dp(n+1);
        dp[0]=dp[1]=1;
        for(int i = 2; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};




class Solution {
public:
    int climbStairs(int n) {
        int dp1=1,dp2=1;
        for(int i = 2; i <= n; i++){
            int dp3=dp1+dp2;
            dp2=dp1;
            dp1=dp3;
        }
        
        return dp1;
    }
};




class Solution {
public:
    int solve(vector<int>&dp,int n){
              
              
        if(dp[n]!=-1) return dp[n];
              
        if(n==1 or n==0){
            return dp[n]=1;
        }    
        return dp[n]=solve(dp,n-1)+solve(dp,n-2);    
    }
    
    int climbStairs(int n) {
          
          vector<int>dp(46,-1);
        
         return  solve(dp,n);
    
    }
};