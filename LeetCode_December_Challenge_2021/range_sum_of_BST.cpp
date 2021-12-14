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


class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int sum=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();q.pop();
            if(node->val >= low and node->val <= high) sum+=node->val;
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return sum;
    }
};