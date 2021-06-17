//Two Pointer Approach
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int i=0, j=0;
        int count = 0;
        int prevCount=0;
        int n=nums.size();
       
        while(j < n){
            if(nums[j] >= left && nums[j] <= right){
                prevCount= j-i+1;
                count+=prevCount;
            }else if(nums[j] < left){
                count+=prevCount;
            }else{
                i=j+1;
                prevCount=0;
            }
            j++;
        }
        
        return count;
    }
};