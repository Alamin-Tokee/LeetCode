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