
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        
        root1->val+=root2->val;
        root1->left=mergeTrees(root1->left,root2->left);
        root1->right=mergeTrees(root1->right,root2->right);
        
        return root1;
    }
};



class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        
        stack<pair<TreeNode*,TreeNode*>>st;
        st.push({root1,root2});
        while(!st.empty()){
            TreeNode* x=st.top().first;
            TreeNode* y=st.top().second;
            st.pop();
            if(x==NULL || y==NULL) continue;
            x->val+=y->val;
            if(x->left==NULL){
                x->left=y->left;
            }else{
                st.push({x->left,y->left});
            }
            if(x->right==NULL){
                x->right=y->right;
            }else{
                st.push({x->right,y->right});
            }
        }
        return root1;
    }
};