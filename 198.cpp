class Solution {
public:
    int dp[1001];
    int solve(vector<int>&nums,int n){
        if(n < 0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        return dp[n]=max(solve(nums,n-1),nums[n]+solve(nums,n-2));
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        
        return solve(nums,nums.size()-1);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        int prevByOne=0;
        int prevByTwo=0;
        for (int i=0; i<nums.size(); i++) {
            int cur=max(nums[i]+prevByTwo, prevByOne);
            prevByTwo=prevByOne;
            prevByOne=cur;
        }
        return prevByOne;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        if(nums.size()>1)
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<dp.size();i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};