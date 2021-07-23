//Brute Force Approach
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    bool checkOne(TreeNode* root){
        if(!root)
            return false;
        
        if(root->val == 1)
            return true;
        
        return checkOne(root->left) || checkOne(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        
        pruneTree(root->left);
        pruneTree(root->right);
        
        if(!checkOne(root->left)) root->left=NULL;
        if(!checkOne(root->right)) root->right=NULL;
        
        if(!root->left && !root->right && root->val == 0) return NULL;
        
        return root;
    }
};