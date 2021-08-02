
//HashMap Solution
//Time Complexity O(n)
//Space Complexity O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int val = target - nums[i];
            if(mp.count(val)){
                return {mp[val],i};
            }
            mp[nums[i]] = i;
            
        }
        return {};
    }
};


//Two Pointer Solution
//Time Complexity O(n*logn)
//Space Complexity O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>arr(nums.size());
        for(int i=0;i<nums.size();i++){
            arr[i]=make_pair(nums[i],i);
        }
        sort(arr.begin(),arr.end());
        int left = 0, right = nums.size()-1;
        
        while(left < right){
            int sum = arr[left].first + arr[right].first;
            if(sum == target){
                return {arr[left].second,arr[right].second};
            }else if(sum < target){
                left++;
            }else{
                right--;
            }
        }
        return {};
    }
};