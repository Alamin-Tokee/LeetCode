//Iterative Solution
//Time Complexity O(n^2)
//Space Complexity (n)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res = {{}};
        vector<int> curr;
        int size;
        
        for (auto num : nums) {
            size = res.size();
            
            for (int i = 0; i < size; i++) {
                curr = res[i];
                curr.push_back(num);
                if (find(res.begin(), res.end(), curr) == res.end())
                    res.push_back(curr);
            }
        }
        
        return res;
    }
};

//Iterative Solution(bit masking)
//Time Complexity O(n^2)
//Space Complexity (n)

// if nums has 3 elements 
//so one can select elements in 8 ways 
// 0 0 0
// 0 0 1
// 0 1 0
//0 1  1
// 1 0 0
// 1 0 1
//1 1 0
//1 1 1

//so select only elements which is 1 , so this way we can create different subsets

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end()); // sort the numbers for removing any duplicate set creation later
     //for eg. [1 2 3 4 4] & [3 2 4 4 1] are same only
        int mask = 1<<nums.size(); // 1<<num.size is equilvalent to pow(2,num.size()) in binary form
        vector<int> vec;
        set<vector<int>> s;//for storing unique set of elements 
        for(int i=0;i<mask;i++){
            
            for(int j=0;j<nums.size();j++){
                
             //convert j to binary and & with i if that is non zero then add it to vec
                if(1<<j & i){
                    vec.push_back(nums[j]);
                }
                
            }
            
            s.insert(vec);
            vec.clear();
        }
        vector<vector<int>> ans;//convert thr result to vector and return
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};

//Recusive Solution(BackTracking)
//Time Complexity O(n*2^n)
//Space Complexity (n)

class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, vector<int> temp, int idx) {
        result.push_back(temp);
        if(idx >= nums.size())
            return;
        
        for(int i = idx; i<nums.size(); i++) {
            if(i > idx && nums[i] == nums[i-1]) continue; //avoid duplicates
            
            temp.push_back(nums[i]);     //include
            backtrack(nums, temp, i+1);  //explore
            temp.pop_back();             //exclude
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        
        vector<int> temp;
        sort(begin(nums), end(nums)); //will help avoiding duplicates
        backtrack(nums, temp, 0);
        
        return result;
    }
};

class Solution {
public:
    void subsetUtil(vector<int> A, vector<vector<int>> &ans, vector<int> temp, int index,
                set<vector<int>> &s){
    if(s.find(temp) == s.end()){
        ans.push_back(temp);
        s.insert(temp);
    }   
    
    for(int i=index;i<A.size();++i){
        temp.push_back(A[i]);
        
        subsetUtil(A, ans, temp, i+1, s);
        
        temp.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& A) {
        sort(A.begin(),A.end());
    
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> temp;

        subsetUtil(A,ans,temp,0,s);

        return ans;
    }
};

void helper(vector<int>& nums,vector<vector<int>>& res,vector<int> temp,int idx,int flag){
        
        if(idx==nums.size()){
            res.push_back(temp);
            temp.clear();
            return;
        }
        if(flag==0 || nums[idx]!=nums[idx-1])
        helper(nums,res,temp,idx+1,0);
        temp.push_back(nums[idx]);
        helper(nums,res,temp,idx+1,1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>temp;
        helper(nums,res,temp,0,0);
        return res;
    }