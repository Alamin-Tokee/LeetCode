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


