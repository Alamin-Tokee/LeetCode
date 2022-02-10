//TC O(n)
//SC O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sz = nums.size();
        map<int,int>mp;
        int sum = 0, count = 0;
        mp[0]++;
        for(int i=0;i<sz;i++){
            sum += nums[i];
            if(mp.find(sum-k)!=mp.end())
                count+=mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};

