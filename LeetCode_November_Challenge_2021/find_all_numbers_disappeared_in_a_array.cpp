// Time Complexity O(n)
// Space Complexity O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        for(int i=0;i<n;i++) m[nums[i]]++;
        vector<int>res;
        for(int i=1;i<=n;i++){
            if(!m[i]) res.push_back(i);
        }
        return res;
    }
};

//Time Complexity O(nlogn)
//Space Complexity O(sort)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>res;
        for(int i=1;i<n;i++){
            if(!binary_search(nums.begin(),nums.end(),i)) res.push_back(i);
        }
        return res;
    }
};

//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(auto c : nums)
            nums[abs(c)-1] = -abs(nums[abs(c)-1]);   // mark c is present by negating nums[c-1]
        for(int i = 0; i < size(nums); i++) 
            if(nums[i] > 0) ans.push_back(i+1);      // nums[i] > 0 means i+1 isnt present in nums
        return ans;
    }
};