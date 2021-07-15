//Brute Force 
//Time Complexity O(n^3)
//Space Complexity O(1)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i] + nums[j] > nums[k] && nums[i] + nums[k] > nums[j] && nums[k] + nums[j] > nums[i]) count++;
                }
            }
        }
        return count;
    }
};

//Binary Search Approach 
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res=0, n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=n-1; i>=0; i--){
            int lo=0,hi=i-1;
            
            while(lo < hi){
                if(nums[lo]+nums[hi] > nums[i]){
                    res+=hi-lo;
                    hi--;
                }else lo++;
            }
        }
        return res;
    }
};

//Binary Search Approach
//Time Complexity O(n^2logn)
//Space Complexity O(logn)
class Solution {
public:
    int binarySearch(vector<int>& nums,int l,int r,int x){
        while(r >= l && r < nums.size()){
            int mid=(l+r)/2;
            if(nums[mid] >= x){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
    int triangleNumber(vector<int>& nums) {

        int count = 0;
        sort(begin(nums),end(nums));
        for(int i=0;i<nums.size()-2;i++){
            int k=i+2;
            for(int j=i+1;j<nums.size()-1 && nums[i]!=0 ; j++){
                k=binarySearch(nums,k,nums.size()-1,nums[i]+nums[j]);
                count += k-j-1;
            }
        }
        return count;
    }
};