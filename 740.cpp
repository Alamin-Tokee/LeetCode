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

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
    int maxi = *max_element(nums.begin(),nums.end());
    int dp[20005];
    vector<int> freq(20005);
    
    for(auto i:nums)
    {
        freq[i]++;
    }
    
    dp[1] = freq[1];
    
    dp[2] = max(dp[1], freq[2]*2);
    
    for(int i=3;i<=maxi;i++)
    {
        dp[i] = max(freq[i]*i+dp[i-2],dp[i-1]);

    }
    
    return dp[maxi];
    }
};