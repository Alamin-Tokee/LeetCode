class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int  val=INT_MAX;
        while(left<right){
            int mid=left+(right-left)/2;
            
            if(nums[mid] < nums[right]){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return nums[left];
    }
};

class Solution {
public:
    int binarySearch(vector<int>&nums,int left,int right){
        if(left==right){
            return nums[left];
        }
        int mid=left+(right-left)/2;
        if(nums[mid] < nums[right]){
            return binarySearch(nums,left,mid);
        }else{
            return binarySearch(nums,mid+1,right);
        }
    }
    int findMin(vector<int>& nums) {
        
        return binarySearch(nums,0,nums.size()-1);
    }
};