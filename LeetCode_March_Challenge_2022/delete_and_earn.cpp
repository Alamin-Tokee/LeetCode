//TC O(N+k) where N is number of element and k is recursive call
//SC O(N+k)
class Solution {
public:
    vector<int>dp;
    int solve(int pos,vector<int>&a){
        if(pos >= a.size()) return 0;
        
        if(dp[pos]!=-1) return dp[pos];
        
        return dp[pos]=max(a[pos]+solve(pos+2,a),solve(pos+1,a));
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> a(*max_element(nums.begin(), nums.end())+1, 0);
        for(auto child:nums){
            a[child]+=child;
        }
        dp.resize(10001,-1);
        
        return solve(0,a);
    }
};

//TC O(N) 
//SC O(N)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> a(n, 0);
        for(auto child:nums){
            a[child]+=child;
        }
        int skip = 0, take = 0;
        int skipi = 0, takei = 0;
        for(int i = 0; i<n; i++){
            takei = skip+a[i];
            skipi = max(skip,take);
            take = takei;
            skip = skipi;
        }
        
        return max(skip,take);
    }
};

//TC O(N+k) where N is number of element and k is recursive call
//SC O(N+k)
class Solution{
public:
    int dp[10001];
    int helper(vector<int>&arr,int index){
        if(index == 0) return arr[index];
        if(index < 0) return 0;
        if(dp[index]!=-1) return dp[index];
        return dp[index] = max(helper(arr,index-1),arr[index]+helper(arr,index-2));
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int>arr(10001,0);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]+=nums[i];
        }
        return helper(arr, *max_element(nums.begin(), nums.end()));
    }
};

//TC O(N)
//SC O(N)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> f(10001,0);
        for(auto ele:nums){
            f[ele]+=1;
        }
        vector<int> dp(10001,0);
        dp[1]=f[1];
        for(int i=2;i<=10000;i++){
            dp[i]=max(dp[i-1],i*f[i]+dp[i-2]);
        }
        return dp[10000];
    }
};