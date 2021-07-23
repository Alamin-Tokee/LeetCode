//Brute Force Approach
//Time Complexity O(n^2)
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

//Optimal Approach
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    bool hasOne(TreeNode* root){
        if(!root) return NULL;
        bool left=hasOne(root->left), right=hasOne(root->right);
        if(!left)  root->left=NULL;
        if(!right) root->right=NULL;
        
        return root->val == 1 || left || right;
    }
    TreeNode* pruneTree(TreeNode* root){
        return (hasOne(root)) ? root : NULL;
    }
};      
