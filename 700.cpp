
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        
        if(root->val == val) return root;
        if(root->val > val) return searchBST(root->left,val);
        
        return searchBST(root->right,val);
    }
};


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        
        if(root->val == val) return root;
        
        return root->val > val ? searchBST(root->left,val) : searchBST(root->right,val);
    }
};


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        
        if(root->val == val) return root;
        
        else if(root->val > val) return searchBST(root->left,val);
        
        else return searchBST(root->right,val);
    }
};