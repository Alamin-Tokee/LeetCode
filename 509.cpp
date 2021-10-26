class Solution {
public:
    int dp[50]={0};
    int fib(int n) {
        if(n==0 || n==1) return dp[n]=n;
        if(dp[n]!=0) return dp[n];
        return dp[n]=fib(n-1)+fib(n-2);
    }
};

class Solution {
public:
    int dp[31];
    int solve(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = fib(n-1)+fib(n-2);
    }
    int fib(int n){
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};