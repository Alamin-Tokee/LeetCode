//Recursive Approach

class Solution {
public:
    vector<TreeNode*>help(int start,int end){
        vector<TreeNode*>ans;
        if(start > end){
            ans.push_back(NULL);
            return ans;
        }
        for(int cur=start; cur<=end; ++cur){
            vector<TreeNode*> leftTrees=help(start,cur-1);
            vector<TreeNode*> rightTrees=help(cur+1,end);
            for(auto left_tree : leftTrees){
                for(auto right_tree : rightTrees){
                    TreeNode *node=new TreeNode(cur,left_tree,right_tree);
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return help(1,n);
    }
};

//Dynamic Programming Solution (2 Approach)

class Solution {
public:
    vector<TreeNode*>help(int start,int end,unordered_map<int,vector<TreeNode*>> &dp){
        vector<TreeNode*>ans;
        if(start > end){
            ans.push_back(NULL);
            return ans;
        }
        int x=start*10+end;
        if(dp.count(x)) return dp[x];
        
        for(int cur=start; cur<=end; ++cur){
            vector<TreeNode*> leftTrees=help(start,cur-1,dp);
            vector<TreeNode*> rightTrees=help(cur+1,end,dp);
            for(auto left_tree : leftTrees){
                for(auto right_tree : rightTrees){
                    TreeNode *node=new TreeNode(cur,left_tree,right_tree);
                    ans.push_back(node);
                }
            }
        }
        dp[x]=ans;
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        unordered_map<int,vector<TreeNode*>>dp;
        return help(1,n,dp);
    }
};


class Solution {
public:
    vector<TreeNode*>help(int start,int end,map<pair<int,int>,vector<TreeNode*>> &dp){
        vector<TreeNode*>ans;
        if(start > end){
            ans.push_back(NULL);
            return ans;
        }

        if(dp.count({start,end})) return dp[{start,end}];
        
        for(int cur=start; cur<=end; ++cur){
            vector<TreeNode*> leftTrees=help(start,cur-1,dp);
            vector<TreeNode*> rightTrees=help(cur+1,end,dp);
            for(auto left_tree : leftTrees){
                for(auto right_tree : rightTrees){
                    TreeNode *node=new TreeNode(cur,left_tree,right_tree);
                    ans.push_back(node);
                }
            }
        }
        dp[{start,end}]=ans;
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int,int>,vector<TreeNode*>>dp;
        return help(1,n,dp);
    }
};

//Iterative Solution 
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> dp[1<<n];
        for(int i=0;i<(1<<n);i++){
            if(i==0){
                dp[i].push_back(nullptr);
            }else{
                for(int j=0;j<n;j++){
                    if(i&(1<<j)){
                        int leftMask=0, rightMask=0;
                        for(int k=0;k<n;k++){
                            if(k==j) continue;
                            if(i & (1 << k) && k < j) leftMask|=1<<k;
                            else if(i & (1 << k)) rightMask|=1<<k;
                        }
                        vector<TreeNode*>leftTrees=dp[leftMask],rightTrees=dp[rightMask];
                        for(TreeNode* l:leftTrees){
                            for(TreeNode* r:rightTrees){
                                dp[i].push_back(new TreeNode(j+1,l,r));
                            }
                        }
                    }
                }
            }
        }
        return dp[(1<<n)-1];
    }
};