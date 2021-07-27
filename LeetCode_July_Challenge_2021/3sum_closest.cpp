// Two Pointer Approach
//Time Complexity O(n^2)
//Space Complesity O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int diff=INT_MAX,n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            int left = i+1,right = n-1;
            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];
                if(abs(target-sum) < abs(diff)){
                    diff=target-sum;
                }
                else if(sum<target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return target - diff;
    }
};


class Solution {
public:
   int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(), nums.end());
         int minDis = INT_MAX;
         int minRes = INT_MAX;
         for(int i = nums.size()-1; i >= 2; --i){
             int left = 0;
             int right = i-1;
             while(left < right){
                 int total = nums[left] + nums[right] + nums[i];
                 if(total == target) 
                     return target;
                 else if(total < target)
                     left ++;
                 else
                     right--;
                        
                 if(abs(target-total) < minDis){
                        minRes = total;
                        minDis = abs(target-total);
                 }
             }
         }
         return minRes;
     } 
};
    


    
