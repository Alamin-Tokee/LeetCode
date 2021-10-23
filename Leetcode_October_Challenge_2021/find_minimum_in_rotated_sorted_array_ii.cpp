class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            
            if(nums[mid] < nums[right]){
                right=mid;
            }else if(nums[mid] > nums[right]){
                left=mid+1;
            }else{
                right--;
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
        if(nums[left]==nums[right]){
            return min(binarySearch(nums,left,mid),binarySearch(nums,mid+1,right));
        }
        else if(nums[mid] > nums[right]){
            return binarySearch(nums,mid+1,right);
        }else{
            return binarySearch(nums,left,mid);
        }
    }
    int findMin(vector<int>& nums) {
        return binarySearch(nums,0,nums.size()-1);
    }
};


//Here is the idea behind the problem

// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int left=0,right=nums.size()-1;
//         int  val=INT_MAX;
//         while(left<right){
//             int mid=left+(right-left)/2;
            
//             if(nums[mid] < nums[right]){
//                 right=mid;
//             }else{
//                 left=mid+1;
//             }
//         }
//         return nums[left];
//     }
// };