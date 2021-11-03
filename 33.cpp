class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[lo]<=nums[mid]){
                if(nums[lo]<=target and nums[mid]>=target){
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }else{
                if(nums[mid]<=target and nums[hi] >= target){
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }
        }
        return -1;
    }
};