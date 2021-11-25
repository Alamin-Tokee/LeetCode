
//Time Complexity O(n)
//Space Complexity O(1)

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

//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1];
        dp[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=max(nums[i],dp[i-1]+nums[i]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};


//Time Complexity O(nlogn)
//Space Complexity O(1)
class Solution {
public:
    int helper(vector<int>&nums,int left,int right){
        if(left > right) return INT_MIN;
        
        int mid=left+(right-left)/2;
        
        int leftAns=helper(nums,left,mid-1);
        int rightAns=helper(nums,mid+1,right);
        
        int leftSum=0,rightSum=0;
        for(int i=mid-1,sum=0;i>=left;i--){
            sum+=nums[i];
            leftSum=max(leftSum,sum);
        }
        
        for(int i=mid+1,sum=0;i<=right;i++){
            sum+=nums[i];
            rightSum=max(rightSum,sum);
        }
        
        int maxSubArray=max(leftAns,rightAns);
        int currentSubArray=nums[mid]+leftSum+rightSum;
        
        return max(maxSubArray,currentSubArray);
    }
    int maxSubArray(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};