class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<=n;j++){
                if(j>=i) dp[j]=max(dp[j],dp[j-i]*i);
            }
        }
        return dp[n];
    }
};


class Solution {
public:
    int dp[59][59];
    int fun(int n, int curr){
        if(n == 0 || curr == 0) return 1;
        if(dp[n][curr] != -1) return dp[n][curr];
        if(curr > n) return dp[n][curr] = fun(n-0, curr-1);
        return dp[n][curr] = max(fun(n-0, curr-1), curr*fun(n-curr, curr));
    }
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        return fun(n, n-1);
    }
};


