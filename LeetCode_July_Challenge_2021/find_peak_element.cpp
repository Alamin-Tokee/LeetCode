//Intution Approach
//Time Complexity O(n)
//Space Complexity O(1)


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] > nums[i+1]) return i;
        }
        
        return nums.size()-1;
    }
};


//Recursive Binary Search Approach
//Time Complexity O(log n)
//Space Complexity O(1)

class Solution {
public:
    int binarySearch(vector<int>&nums,int l,int r){
        if(l==r) return l;
        int mid=(l+r)/2;
        if(nums[mid] > nums[mid+1]) return binarySearch(nums,l,mid);
        
        return binarySearch(nums,mid+1,r);
    }
    int findPeakElement(vector<int>& nums) {
    
        return binarySearch(nums,0,nums.size()-1);
    }
};