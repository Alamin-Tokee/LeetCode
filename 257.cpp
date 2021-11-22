
class Solution {
public:
    vector<string>res;
    void dfs(TreeNode* root,string path){
        if(!root) return;
        if(path=="") path=to_string(root->val);
        else path += "->"+to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            res.push_back(path);
        }
        dfs(root->left,path);
        dfs(root->right,path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return res;
        dfs(root,"");
        
        return res;
    }
};


class Solution {
public:
    void dfs(TreeNode* root,string path,vector<string>&res){
        if(!root) return;
        path+=to_string(root->val);
        if(!root->left && !root->right){
            res.push_back(path);
        }
        path+="->";
        dfs(root->left,path,res);
        dfs(root->right,path,res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        if(!root) return res;
        dfs(root,"",res);
        
        return res;
    }
};