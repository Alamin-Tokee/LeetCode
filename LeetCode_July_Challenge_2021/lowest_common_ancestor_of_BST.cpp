//Time Complexity O(h)
//Space Complexity O(h)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(!root) return NULL;
         if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);
         if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
         return root;
	}
};


//Time Complexity O(h)
//Space Complexity O(h)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        
        if(root->val==p->val || root->val == q->val) return root;
        
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        
        if(l && r) return root;
        
        return l ? l : r;
	}
};
