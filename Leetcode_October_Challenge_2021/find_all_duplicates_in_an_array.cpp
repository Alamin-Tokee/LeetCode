class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        // for(auto it=mp.begin();it!=mp.end();it++){
        //     if(it->second > 1){
        //         ans.push_back(it->first);
        //     }
        // }
        for(auto it:mp){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=1;
        vector<int> ans;

        while(j<nums.size())
        {
            if(nums[j]==nums[j-1])
               ans.push_back(nums[j++]);
            else
                j++;
        }
         return ans;
    }
};


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        
        while(j<nums.size())
        {
            if(nums[j]==nums[j-1])
                swap(nums[j++],nums[i++]);
            else
                j++;
        }
        vector<int> ans;
        j=0;
        while(j<i)
        {
            ans.push_back(nums[j++]);
        }
        return ans;
    }
};