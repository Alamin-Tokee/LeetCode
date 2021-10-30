class Solution {
public:
    bool isSame(TreeNode* r1,TreeNode* r2){
        if(!r1 and !r2) return true;
        if(!r1 or !r2) return false;
        return r1->val == r2->val and isSame(r1->left,r2->right) and isSame(r1->right,r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSame(root,root);
    }
};

