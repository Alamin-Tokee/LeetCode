class Solution {
public:
    void permutationHelper(vector<vector<int>>&res,vector<int>&nums,vector<int>&temp){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(find(temp.begin(),temp.end(),nums[i])==temp.end()){
                temp.push_back(nums[i]);
                permutationHelper(res,nums,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        
        permutationHelper(res,nums,temp);
        
        return res;
    }
};


class Solution {
public:
    void permute(vector<vector<int>> &ans,int idx, vector<int> &arr){
        if(idx == arr.size()-1){
            ans.push_back(arr);
            return;
        }
        for (int i = idx; i < arr.size();i++){
            swap(arr[i], arr[idx]);
            permute(ans, idx + 1, arr);
            swap(arr[i], arr[idx]);
        }

    }
    vector<vector<int>> permute(vector<int>& arr) {
        vector<vector<int>> ans;
        permute(ans, 0, arr);
        return ans;
    }
    
};


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        do{
            vector<int>v(0);
            for(auto &i:nums){
                v.push_back(i);
            }
            result.push_back(v);
        }while(next_permutation(nums.begin(),nums.end()));
       return result;
    }
};