
class Solution {
public:
    bool bstLesser(TreeNode* root,int val){
        if(!root) return true;
        
        if(root->val > val && bstLesser(root->left,val) && bstLesser(root->right,val)){
            return true;
        }else{
            return false;
        }
    }
    bool bstGreater(TreeNode* root,int val){
        if(!root) return true;
        
        if(root->val < val && bstGreater(root->left,val) && bstGreater(root->right,val)){
            return true;
        }else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        // if(bstGreater(root->left,root->val) && bstLesser(root->right,root->val) && isValidBST(root->left) && isValidBST(root->right)){
        //     return true;
        // }else{
        //     return false;
        // }
        
        return bstGreater(root->left,root->val) && bstLesser(root->right,root->val) && isValidBST(root->left) && isValidBST(root->right);
    }
};




class Solution {
public:
    bool dfs(TreeNode* root,long minVal,long maxVal){
        if(!root) return true;
        
        if(root->val > minVal && root->val < maxVal && dfs(root->left, minVal, root->val) && dfs(root->right,root->val,maxVal)){
            return true;
        }else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        return dfs(root,LONG_MIN,LONG_MAX);
    }
};