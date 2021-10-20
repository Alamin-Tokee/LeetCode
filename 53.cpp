class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ma=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            ma=max(nums[i],ma+nums[i]);
            ans=max(ans,ma);
        }
        return ans;
    }
};