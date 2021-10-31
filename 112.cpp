class Solution {
public:
    bool dfs(TreeNode* root,int &target,int sum){
        if(!root) return false;
        sum+=root->val;
        if(sum==target and root->left==NULL and root->right==NULL) return true;
        
        bool l=dfs(root->left,target,sum);
        bool r=dfs(root->right,target,sum);
        
        return (l or r); 
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
    
        return dfs(root,targetSum,0);
    }
};


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {        
        if(root == NULL) return false;
        targetSum -= root->val;
        
        if(root->left == NULL && root->right == NULL){
            return (targetSum == 0) ? true : false;
        }
        return (hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum));        
    }
};



class Solution {
public:
    bool helper(TreeNode * root , int targetSum , int sum){
        if(!root) return false ;
        
        sum += root->val;
        if(root->left == NULL && root->right == NULL){
           if(sum == targetSum) return true;
            else {
                sum -= root->val; // backtrack  
                return false ;
            }
        }
        bool left = helper(root->left, targetSum ,sum);
        bool right = helper(root->right ,targetSum ,sum);
        return left || right;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
       return  helper(root , targetSum, sum );
        
    }
};