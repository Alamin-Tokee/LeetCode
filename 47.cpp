class Solution {
public:
    void permutation(vector<int>&nums,int index,int number,vector<vector<int>>&res){
        if(index==number){
            if(find(res.begin(),res.end(),nums)==res.end()){
                res.push_back(nums);
            }
        }
        for(int i=index;i<number;i++){
            swap(nums[index],nums[i]);
            permutation(nums,index+1,number,res);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        permutation(nums,0,nums.size(),res);
        
        return res;
    }
};