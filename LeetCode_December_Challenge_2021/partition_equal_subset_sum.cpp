class Solution {
public:
    bool isPossible(vector<int>&nums,int n,int sum){
        vector<vector<int>>dp(n+1,vector<int>(sum+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j==0) dp[i][j]=true;
                else if(i==0) dp[i][j]=false;
                else if(nums[i-1] <= j){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto &i:nums){
            sum+=i;
        }
        if(sum%2!=0) return false;
        bool ans=isPossible(nums,n,sum/2);
        return ans;
    }
};




class Solution {
public:
    int8_t dp[201][10001] = {[0 ... 200] = {[0 ... 10000] = -1}};
    bool isPossible(vector<int>&nums,int sum,int i = 0){
        if(sum == 0) return true;
        if(i >= size(nums) || sum < 0) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum]= isPossible(nums,sum-nums[i],i+1) || isPossible(nums,sum,i+1);
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=accumulate(begin(nums),end(nums),0);
        if(totalSum & 1) return false;
        
        return isPossible(nums,totalSum/2);
    }
};