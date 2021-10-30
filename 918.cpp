class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int minSum,maxSum,t1Sum,t2Sum,allSum;
        minSum=maxSum=t1Sum=t2Sum=allSum=nums[0];
        for(int i=1;i<n;i++){
            t1Sum=max(nums[i],t1Sum+nums[i]);
            maxSum=max(maxSum,t1Sum);
            
            t2Sum=min(nums[i],t2Sum+nums[i]);
            minSum=min(minSum,t2Sum);
            
            allSum+=nums[i];
        }
        return maxSum > 0 ? max(maxSum,allSum-minSum) : maxSum;
    }
};


class Solution {
public:
    int maxSubarraySum(vector<int>&num){
        int localMax=num[0];
        int subSum=num[0];
        for(int i=1;i<num.size();i++){
            localMax=max(num[i],localMax+num[i]);
            subSum=max(subSum,localMax);
        }
        return subSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxLinear=maxSubarraySum(nums);
        
        int totalSum=0;
        for(auto& a:nums){
            totalSum+=a;
            a*=-1;
        }
        int maxCircular = maxLinear > 0 ? totalSum+maxSubarraySum(nums) : totalSum-maxSubarraySum(nums);
        
        return max(maxLinear,maxCircular);
    }
};





