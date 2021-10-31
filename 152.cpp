class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result=nums[0],minVal=nums[0],maxVal=nums[0];
        for(int i=1;i<nums.size();i++){
            int tmp=maxVal;
            maxVal=max(nums[i],max(tmp*nums[i],minVal*nums[i]));
            minVal=min(nums[i],min(tmp*nums[i],minVal*nums[i]));
            result=max(result,max(minVal,maxVal));
        }
        return result;
    }
};