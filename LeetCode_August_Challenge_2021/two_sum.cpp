
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