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


