class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int f1=0,f2=0;
        for(int i=0;i<n;i++){
            int f0=cost[i]+min(f1,f2);
            f2=f1;
            f1=f0;
        }
        return min(f1,f2);
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]+=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};

class Solution {
public:
    int dp[1001];
    int solve(vector<int>&cost,int index){
        if(index==0 or index==1) return cost[index];
        
        if(dp[index]!=-1) return dp[index];
        
        return dp[index]=cost[index]+min(solve(cost,index-1),solve(cost,index-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        cost.push_back(0);
        return solve(cost,cost.size()-1);
    }
};