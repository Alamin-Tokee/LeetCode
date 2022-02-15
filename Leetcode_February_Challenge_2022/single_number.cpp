//TC O(n)
//SC O(1)

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


//TC O(n)
//SC O(1)
class Solution {
public:
    int singleNumber(const vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};


//TC O(n)
//SC O(n)
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



//TC O(n)
//SC O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            if(!st.count(nums[i])){
                st.insert(nums[i]);
            }else{
                st.erase(nums[i]);
            }
        }
        return *st.begin();
    }
};


//TC O(n)
//SC O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(int i = 0; i < nums.size(); i++){
            if(hashSet.find(nums[i]) != hashSet.end())
                hashSet.erase(nums[i]);
            else
                hashSet.insert(nums[i]);
        }        
        auto it = hashSet.begin();
        return *it;
    }
};