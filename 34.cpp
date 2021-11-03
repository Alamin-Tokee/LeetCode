class Solution {
public:
    int firstPos(vector<int>&nums,int lo,int hi,int target){
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid] < target){
                lo=mid+1;
            }else if(nums[mid] > target){
                hi=mid-1;
            }else{
                if(mid==0 || nums[mid-1] < nums[mid]) return mid;
                else hi=mid-1;
            }
        }
        return -1;
    }
    int lastPos(vector<int>&nums,int lo,int hi,int target){
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid] < target){
                lo=mid+1;
            }else if(nums[mid] > target){
                hi=mid-1;
            }else{
                if(mid==nums.size()-1 || nums[mid] < nums[mid+1]) return mid;
                else lo=mid+1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans={-1,-1};
        int n=nums.size();
        
        if(n==0) return ans;
        ans[0]=firstPos(nums,0,n-1,target);
        ans[1]=lastPos(nums,0,n-1,target);
        
        return ans;
    }
};