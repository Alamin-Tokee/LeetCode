class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int reachable = 0;
        for(int i=0;i<n;i++){
            if(reachable < i){
                return false;
            }
            reachable=max(reachable,i+nums[i]);
        }
        return true;
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            if( maxi >= i) maxi=max(maxi,i+nums[i]);
        }
        return maxi >= (n-1);
    }
};


class Solution {
public:
    int dp[10005];
    int helper(vector<int>& nums,int index,int n){
        if(index == n-1) return true;
        if(index >= n) return false;
        
        if(dp[index]!=-1) return dp[index];
        
        for(int i=1;i<=nums[index];i++){
            if(helper(nums,index+i,n)) return dp[index]=true;
        }
        return dp[index] = false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return helper(nums,0,n);
    }
};
