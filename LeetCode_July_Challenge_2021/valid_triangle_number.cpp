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