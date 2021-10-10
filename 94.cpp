class Solution {
public:
    vector<int>ans;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        dfs(root);
        
        return ans;
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        stack<TreeNode*>st;
        //st.push(root);
        TreeNode* cur=root;
        while(!st.empty() || cur!=NULL){
            while(cur!=NULL){
                st.push(cur);
                cur=cur->left;
            }
            cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            cur=cur->right;
        }
        
        return ans;
    }
};


    //Stack Inorder
    // vector<int> helper(TreeNode* root){
    //     vector<int> ans;
    //     stack<TreeNode*>s;
    //     TreeNode* curr = root;
    //     while(!s.empty() or curr!=NULL){
    //         if(curr!=NULL){
    //             s.push(curr);
    //             curr = curr->left;
    //         }else{
    //             curr = s.top();
    //             s.pop();
    //             ans.push_back(curr->val);
    //             curr = curr->right;
    //         }
    //     }
    //     return ans;
    // }