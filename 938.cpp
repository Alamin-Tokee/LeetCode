//Approach 1
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        if(root->val < low){
            return rangeSumBST(root->right,low,high);
        }
        if(root->val > high){
            return rangeSumBST(root->left,low,high);
        }
        return root->val+rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
    }
};

//Approach 2
class Solution {
    int sum=0;
public:
    void dfs(TreeNode* root,int l,int r){
        if(!root) return;
        
        if(root->val >= l and root->val <= r){
            sum+=root->val;
        }
        dfs(root->left,l,r);
        dfs(root->right,l,r);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        this->sum=sum;
        dfs(root,low,high);
        
        return sum;
    }
};