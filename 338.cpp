class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=1;i<=n;i++){
            ans[i]=ans[i/2]+i%2;
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> dp(num+1, 0);
        
        for (int i = 1; i <= num; ++i)          
            dp[i] = dp[i&(i-1)] + 1;
        
        return dp;
    }
};