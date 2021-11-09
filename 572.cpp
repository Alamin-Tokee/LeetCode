
class Solution {
public:
    bool dfs(TreeNode* root,TreeNode* subRoot){
        if(!root and !subRoot) return true;
        if(!root or !subRoot) return false;
        if(root->val!=subRoot->val) return false;
        
        return dfs(root->left,subRoot->left) && dfs(root->right,subRoot->right);;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root and !subRoot) return true;
        if(!root or !subRoot) return false;
        
        return dfs(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};