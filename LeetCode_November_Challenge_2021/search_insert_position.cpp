class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int mid=0;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid] < target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return left;
    }
};


class Solution {
public:
    int binarySearch(vector<int>&nums,int l,int r,int t){
        if(l > r) return l;
        int mid = (l+r) >> 1;
        if(nums[mid] < t) return binarySearch(nums,mid+1,r,t);
        
        return binarySearch(nums,l,mid-1,t);
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums,0,size(nums)-1,target);
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(begin(nums),end(nums),target) - begin(nums);
    }
};