//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    void getSum(TreeNode* root,long int& totalSum){
        if(!root) return;
        
        totalSum+=root->val;
        getSum(root->left,totalSum);
        getSum(root->right,totalSum);
    }
    long int getMaxProduct(TreeNode* root,long int totalSum,long int& res){
        if(!root) return 0;
        long int curSum=root->val;
        long int left=getMaxProduct(root->left,totalSum,res);
        long int right=getMaxProduct(root->right,totalSum,res);
        res=max(res,max(((long)(totalSum-left)*(left)),((long)(totalSum-right)*(right))));
        curSum+=left+right;
        return curSum;
    }
    int maxProduct(TreeNode* root) {
        if(!root) return 0;
        long int totalSum=0;
        getSum(root,totalSum);
        
        long int res = INT_MIN;
        getMaxProduct(root,totalSum,res);
        
        return (long)(res) % 1000000007;
    }
};

//Time Complexity O(n)
//Space Complexity O(n)