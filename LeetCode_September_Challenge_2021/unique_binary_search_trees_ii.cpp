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

