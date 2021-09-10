//Time Complexity O(n^2)
//Space Complexity O(n^2)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n < 3) return 0;
        int ans=0;
        vector<unordered_map<long long int,long long int>>dp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long long int diff=(long long)nums[i] - (long long)nums[j];
                dp[i][diff]++;
                if(dp[j].find(diff)!=dp[j].end()){
                    dp[i][diff]+=dp[j][diff];
                    ans+=dp[j][diff];
                }
            }
        }
        return ans;
    }
};