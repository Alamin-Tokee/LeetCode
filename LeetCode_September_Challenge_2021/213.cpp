class Solution {
public:
    int solve(vector<int>&num,int start,int end,int dp[]){
        if(start > end) return 0;
        if(dp[start]!=-1) return dp[start];
        
        return dp[start]=max(num[start]+solve(num,start+2,end,dp),solve(num,start+1,end,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int dp1[n],dp2[n];
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        return max(solve(nums,0,n-2,dp1),solve(nums,1,n-1,dp2));
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
        vector<int> rob1(n);
        vector<int> rob2(n);
        
        rob1[0] = nums[0];
        rob1[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i<n-1; i++) {
            rob1[i] = max(rob1[i - 2] + nums[i], rob1[i - 1]);
        }
        
        rob2[0]= 0;
        rob2[1] = nums[1];
        rob2[2] = max(nums[1], nums[2]);
        for(int i = 3; i<n; i++) {
            rob2[i] = max(rob2[i - 2] + nums[i], rob2[i - 1]);
        }
        
        return max(rob1[n-2], rob2[n-1]);
    }
};

