class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int ans=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]) dp[i]=max(dp[i],dp[j]+1);
            }
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};

//Time Complexity O(nlogn)
//Space Complexity O(n)
class Solution {
public:
    int ceilIndex(vector<int>&nums,int l,int h,int x){
        while(l<h){
            int mid=l+(h-l)/2;
            if(nums[mid] >= x)
                h=mid;
            else
                l=mid+1;
        }
        return h;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis(n,0);
        lis[0]=nums[0];
        int len=1;
        
        for(int i=1;i<n;++i){
            if(nums[i] > lis[len-1]){
                lis[len]=nums[i];
                len++;
            }else{
                int c=ceilIndex(lis,0,len-1,nums[i]);
                lis[c]=nums[i];
            }
        }
        return len;
    }
};
