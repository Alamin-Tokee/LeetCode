
//Recusive 
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};
        
        vector<TreeNode*>ans;
        if(n==1){
            TreeNode* ri=new TreeNode(0);
            ans.push_back(ri);
        }
        
        for(int i=1;i<n;i+=2){
            vector<TreeNode*>l=allPossibleFBT(i);
            vector<TreeNode*>r=allPossibleFBT(n-i-1);
            for(auto left:l){
                for(auto right:r){
                    TreeNode* root=new TreeNode(0);
                    root->left=left;
                    root->right=right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};

//DP
class Solution {
public:
    map<int,vector<TreeNode*>>dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return dp[n]={};
        
        if(n==1){
            TreeNode* ri=new TreeNode(0);
            return dp[n]={ri};
        }
        if(dp.find(n)!=dp.end()) return dp[n];
        vector<TreeNode*>ans;
        for(int i=1;i<n;i+=2){
            for(auto left:allPossibleFBT(i)){
                for(auto right:allPossibleFBT(n-i-1)){
                    TreeNode* root=new TreeNode(0);
                    root->left=left;
                    root->right=right;
                    ans.push_back(root);
                }
            }
        }
        return dp[n]=ans;
    }
};