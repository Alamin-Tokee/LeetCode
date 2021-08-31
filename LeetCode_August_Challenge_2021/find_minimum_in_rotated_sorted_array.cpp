//Time Complexity O(logn)
//Space Complexity O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0, hi=nums.size()-1;
        while(lo < hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid] < nums[hi]){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        return nums[lo];
    }
};
