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