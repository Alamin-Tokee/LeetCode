class Solution {
public:
    int combination(vector<int>&nums,int target,vector<int>&m){
        if(target == 0) return 1;
        
        if(target < 0) return 0;
        
        if(m[target]!=-1) return m[target];
        
        int res=0;
        for(int i=0;i<nums.size();i++){
            res+=combination(nums,target-nums[i],m);
        }
        return m[target]=res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>m(target+1,-1);
        return combination(nums,target,m);
    }
};

class Solution {
public:
    int dp[1001];
    int combination(vector<int>&nums,int target,int n,int sum){
        if(sum > target) return 0;
        
        if(target == sum) return 1;
        
        if(dp[sum]!=-1) return dp[sum];
        
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i] <= target)
            res+=combination(nums,target,n,sum+nums[i]);
        }
        return dp[sum]=res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return combination(nums,target,n,0);
    }
};

class Solution {
public:
int combinationSum4(vector& nums, int target) {

    int n=nums.size();
    
    vector<unsigned int>dp(target+1,0);
    
    dp[0]=1;
    
    for(long long j=1;j<=target;j++){
        
        for(long long i=0;i<nums.size();i++){
            
            if(nums[i]>j){
                continue;
            }
            
            else if(nums[i]<=j){
                dp[j]=dp[j]+dp[j-nums[i]];
            }
            
        }
        
    }
    
    return dp[target];
}
};