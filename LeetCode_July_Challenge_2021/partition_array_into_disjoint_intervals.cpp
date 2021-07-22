
//TC O(n)
//SC O(1)
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        int ma,curr,ans=1;
        ma=curr=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i] < ma){
                ma=curr;
                ans=i+1;
            }else if(nums[i] > curr){
                curr=nums[i];
            }
        }
        
        return ans;
    }
};

//TC O(n)
//SC O(n)
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxl(n),minr(n);
        int maxll=-1;
        for(int i=0;i<n;i++){
            maxll=max(maxll,nums[i]);
            maxl[i]=maxll;
        }
        int minrr=INT_MAX;
        for(int i=n-1;i>=0;i--){
            minrr=min(minrr,nums[i]);
            minr[i]=minrr;
        }
        
        for(int i=0;i<n;i++){
            if(maxl[i]<=minr[i+1]){
                return i+1;
            }
        }
        
        return -1;
    }
};