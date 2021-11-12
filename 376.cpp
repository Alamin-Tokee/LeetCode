class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>>dp(n,vector<int>(2,1));
        int ans = 1;
        
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i]-nums[j] < 0){
                    dp[i][1] = max(dp[i][1],1+dp[j][0]);
                }
                else if(nums[i] - nums[j] > 0){
                     dp[i][0] = max(dp[i][0],1+dp[j][1]);
                }
                ans = max(ans,dp[i][0]);
                ans = max(ans,dp[i][1]);
            }
        }
        return ans;
    }
};