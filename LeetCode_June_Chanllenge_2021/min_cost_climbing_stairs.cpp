//First Approach Using Intution

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int f1=0,f2=0;
        
        for(int i=0;i<n;i++){
            int f3=cost[i]+min(f1,f2);
            f2=f1;
            f1=f3;
        }
        
        return min(f1,f2);
    }
};

//Second Approach Using Dynamic Programming

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp[1001];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        
        return min(dp[n-1],dp[n-2]);
    }
};