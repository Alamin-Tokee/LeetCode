//Recusive Solution (DFS)
//Space Complexity O(n^2)
//Time Complexity O(h)

class Solution {
public:
    vector<vector<int>>result;
    void dfs(TreeNode* root,int targetSum,vector<int>&path,int currSum){
        if(!root) return;
        currSum+=root->val;
        path.push_back(root->val);
        if(!root->left && !root->right && targetSum==currSum){
            result.push_back(path);
        }
        dfs(root->left,targetSum,path,currSum);
        dfs(root->right,targetSum,path,currSum);
        
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        if(!root) return result;
        
        dfs(root,targetSum,path,0);
        return result;
    }
};

//Recusive Solution (DFS)
//Space Complexity O(n^2)
//Time Complexity O(h)
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return ans;
    }
    void dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if (root == nullptr) return;
        path.push_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr) { // Is leaf node
            if (targetSum == 0) // Found valid path
                ans.push_back(path);
        } else {
            dfs(root->left, targetSum, path);
            dfs(root->right, targetSum, path);
        }
        path.pop_back(); // backtrack
    }
};



//For my intution

class Solution {
public:
    void pathStore(TreeNode* root, vector<int>& path, int targetSum, vector<vector<int>>& res){
        if(root == NULL)
            return; 
        path.push_back(root->val);
        if(root->right == NULL and root->left == NULL and targetSum == root->val){
            res.push_back(path);
            path.pop_back();
            return;
        }
        pathStore(root->left, path, targetSum - root->val, res);
        pathStore(root->right, path, targetSum - root->val, res); 
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> res;
        pathStore(root, path, targetSum, res);
        return res;
    }
};


class Solution {
public:
    // vector<vector<int>> res;
    // vector<int> tmp;
    // int target, tmpVal = 0;
    // void dfs(TreeNode *root) {
    //     // support variables
    //     int val = root->val;
    //     // adding the current value to tmp
    //     tmp.push_back(val), tmpVal += val;
    //     // checking if it meets the condition
    //     if (!root->left && !root->right && tmpVal == target) res.push_back(tmp);
    //     // recursive calls
    //     if (root->left) dfs(root->left);
    //     if (root->right) dfs(root->right);
    //     // backtracking
    //     tmp.pop_back(), tmpVal -= val;
    // }
    vector<vector<int>> vc;
    
    void helper(TreeNode* root, int& targetSum, vector<int> curr){
        if(root==NULL)return;
        curr.push_back(root->val);
        int ss = accumulate(curr.begin(),curr.end(),0);
        if(root->left == NULL && root->right==NULL){
            if(ss == targetSum){
                vc.push_back(curr);
                return;
            }
        }
        helper(root->left,targetSum,curr);
        helper(root->right,targetSum,curr);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        helper(root,targetSum,curr);
        return vc;
    }
};