class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int>ans;
        for(auto& v:m){
            if(v.second==1){
               ans.push_back(v.first); 
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        
        for(int i=0;i<nums.size();i++){
            if((i==0 or nums[i-1]!=nums[i]) and (i==nums.size()-1 or nums[i]!=nums[i+1])){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

//Optimal Solution
//Time complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xy=0;
        for(int n:nums) xy^=n;
        xy &= -xy;
        std::vector<int> result={0,0};
        for(int n:nums){
            if(xy & n) result[0]^=n;
            else result[1]^=n;
        }
        return result;
    }
};
