class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int unique=0;
        for(int i=0;i<n;i++){
            unique^=nums[i];
        }
        return unique;
    }
};


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            if(st.count(nums[i])){
                st.erase(nums[i]);
            }
            else st.insert(nums[i]);
        }
        return *begin(st);
    }
};