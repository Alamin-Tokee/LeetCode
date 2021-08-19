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

//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    int mod=1e9+7;
    int getSum(TreeNode* root,vector<long long>&ans){
        if(!root) return 0;
    
        int l=getSum(root->left,ans);
        int r=getSum(root->right,ans);
        int sum=l+r+root->val;
        ans.push_back(sum);
        
        return sum;
    }
    
    int maxProduct(TreeNode* root) {
        if(!root) return 0;
        vector<long long>ans;
        getSum(root,ans);
        
        long long res=INT_MIN;
        for(int i=0;i<ans.size()-1;i++){
            res=max(res,ans[i]*(ans[ans.size()-1]-ans[i]));
        }
        
        return (res % mod);
    }
};

//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    const long long mod=1e9+7;
    long long total;
    long long ans;
    unordered_map<TreeNode*,long long>mp;
    long long getSum(TreeNode* root){
        if(!root) return 0;
        
        // long long curr = 0LL;
        // curr += root->val;
        // if(root->left)curr = curr + getSum(root->left);
        // if(root->right)curr = curr + getSum(root->right);
        
        long long l=getSum(root->left);
        long long r=getSum(root->right);
        long long curr=l+r+root->val;
        mp[root]=curr;
        
        return curr;
    }
    void getMaxProduct(TreeNode* root){
        if(!root) return;
        long long l,r;
        
        r=mp[root];
        l=total-r;
        ans=max(ans,r*l);
        
        
        getMaxProduct(root->left);
        getMaxProduct(root->right);
        return;
    }
    int maxProduct(TreeNode* root) {
        if(!root) return 0;
        ios_base::sync_with_stdio(0);cin.tie(0);
        total=0ll;
        ans=0ll;
        total=getSum(root);
        
        getMaxProduct(root);
        
        return ans % mod;
    }
};
