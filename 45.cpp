class Solution {
public:
    int helper(vector<int>&nums,int start){
        if(start >= nums.size()-1) return 0;
        
        int minJump=INT_MAX;
        for(int i=start+1;i<=start+nums[start];i++){
            minJump=min(minJump,1+helper(nums,i));
        }
        return minJump;
    }
    int jump(vector<int>& nums) {
        return helper(nums, 0);
    }
};


class Solution {
public:
    int dp[100001];
    int helper(vector<int>&nums,int start){
        if(start >= nums.size()-1) return 0;
        if(dp[start]!=-1) return dp[start];
        int minJump=pow(10,7);
        for(int i=start+1;i<=start+nums[start];i++){
            minJump=min(minJump,1+helper(nums,i));
        }
        return dp[start]=minJump;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return helper(nums, 0);
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        int jumpStart=0;
        int jumpEnd=0;
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            jumpEnd=max(jumpEnd,i+nums[i]);
            if(i==jumpStart){
                count++;
                jumpStart=jumpEnd;
            }
        }
        return count;
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        int left=0,right=0;
        int jumpCount=0;
        int maxJump=0;
        while(right<nums.size()-1){
            for(int i=left;i<=right;i++){
                maxJump=max(maxJump,i+nums[i]);
            }
            left=right+1;
            right=maxJump;
            jumpCount++;
        }
        return jumpCount;
    }
};