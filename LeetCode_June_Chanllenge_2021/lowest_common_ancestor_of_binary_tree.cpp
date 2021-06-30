//Time Complexity O(n)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root) return NULL;
        if(root->val==p->val || root->val==q->val) return root;
        
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        
        if(left && right) return root;
        
        return left ? left : right;   
    }
};

//Time Complexity O(n)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root; 
        TreeNode *left = lowestCommonAncestor(root->left, p, q), *right = lowestCommonAncestor(root->right, p, q); 
        if (left && right) return root; 
        return left ? left : right; 
    }
};


class Solution {
public:
    bool isPresent(TreeNode* root,TreeNode* a){
    if(!root) return false;
    if(root->val==a->val) return true;
    return isPresent(root->left,a) || isPresent(root->right,a);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(isPresent(root->right,p) && isPresent(root->right,q)) return lowestCommonAncestor(root->right,p,q);
        if(isPresent(root->left,p) && isPresent(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};