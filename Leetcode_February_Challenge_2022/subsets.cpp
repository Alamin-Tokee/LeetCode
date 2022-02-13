//TC O(N*2^N)
//SC O(N*2^N)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res={{}};
        vector<int>curr;
        int size=0;
        for(auto num:nums){
            size=res.size();
            for(int i=0;i<size;i++){
                curr=res[i];
                curr.push_back(num);
                if(find(res.begin(),res.end(),curr)==res.end()){
                    res.push_back(curr);
                }
            }
        }
        return res;
    }
};

//TC O(N*2^N)
//SC O(N*2^N)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int>v;
        set<vector<int>>res;
        int mask = 1 << nums.size();
        for(int i=0;i<mask;i++){
            for(int j=0;j<nums.size();j++){
                if(1<<j & i){
                    v.push_back(nums[j]);
                }
            }
            res.insert(v);
            v.clear();
        }
        vector<vector<int>>ans;
        for(auto x:res){
            ans.push_back(x);
        }
        return ans;
    }
};


//TC O(N*2^N)
//SC O(N)
class Solution {
public:
    vector<vector<int>>res;
    void backtrack(vector<int>&nums,int idx,vector<int>temp){
        res.push_back(temp);
        if(idx>=nums.size()) return;
        
        for(int i=idx;i<nums.size();i++){
            if(idx > i and nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            backtrack(nums,i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        this->res=res;
        vector<int>temp;
        sort(begin(nums),end(nums));
        backtrack(nums,0,temp);
        
        return res;
    }
};


//TC O(N*2^N)
//SC O(N)
class Solution {
public:
    void getSubsets(int index,vector<int>&nums, vector<int>&subset, vector<vector<int>> &answer){
        if(index==nums.size()){
            answer.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        getSubsets(index+1, nums, subset, answer); // Pick
        subset.pop_back();
        getSubsets(index+1,nums,subset,answer); // Unpick
    }
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> answer;
        vector<int>subset;
        getSubsets(0, nums, subset, answer);
        return answer;
    }
};
