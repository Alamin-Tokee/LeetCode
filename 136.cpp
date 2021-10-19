class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans^=nums[i];
        }
        return ans;
    }
};

class Solution {
public:
    int singleNumber(const vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            if(!mp.count(nums[i]))
                mp.insert({nums[i],0});
            else{
                mp.erase(nums[i]);
                mp.emplace(nums[i],-1);
            }
        }
        for(auto store : mp){
            if(mp.at(store.first) != -1)
                return store.first;
        }
        return 1;
    }
};