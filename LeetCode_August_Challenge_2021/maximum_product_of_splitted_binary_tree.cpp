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

class Solution {
public:
    int mod=1e9+7;
    int tot=0;
    int getSum(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        int left=getSum(root->left);
        int right=getSum(root->right);
        
        root->val+=left+right;
        
        return root->val;
    } 
    
    void getMaxProduct(TreeNode* root,long int& res){
        if(!root) return;
        
        if(root->left){
            long int sum1=root->left->val;
            long int sum2=tot-sum1;
            long int curr=sum1*sum2;
            
            if(res < curr) 
                res=curr;
        }
        if(root->right){
            long int sum1=root->right->val;
            long int sum2=tot-sum1;
            long int curr=sum1*sum2;
            
            if(res < curr) 
                res=curr;
        }
        getMaxProduct(root->left,res);
        getMaxProduct(root->right,res);
    }
    
    int maxProduct(TreeNode* root) {
        if(!root) return 0;
        
        tot=getSum(root);
        
        long int res = INT_MIN;
        getMaxProduct(root,res);
        
        return res % mod;
    }
};
