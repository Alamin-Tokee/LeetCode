class Solution {
public:
    int arithmeticSlices(vector<int>&nums,int i,vector<int>&memo){
        if(i<2 || nums[i]-nums[i-1]!=nums[i-1]-nums[i-2]) return 0;
        if(memo[i]!=-1) return memo[i];
        return memo[i]=arithmeticSlices(nums,i-1,memo)+1;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int>memo(nums.size(),-1);
        int sum=0;
        for(int i=0;i<nums.size();i++) 
            sum+=arithmeticSlices(nums,i,memo);
        
        return sum;
    }
};


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums){
        int ans = 0,dp = 0;
        if(nums.size() < 3) return 0;
        for(int i = 2 ; i < nums.size(); i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                dp = dp+1;
                ans += dp;
            }else dp = 0;
        }
        return ans;
    } 
};


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        int t[n];
        memset(t,0,sizeof(t));
        int ans = 0 ;
        for(int i =2 ;i<n;i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                t[i] = t[i-1]  + 1;
                ans +=t[i];
            }
        }
        return ans;
    }
};