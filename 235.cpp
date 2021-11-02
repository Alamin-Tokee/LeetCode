
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal=p->val;
        int qVal=q->val;
        TreeNode* node=root;
        
        while(node!=NULL){
            
            if(node->val < pVal && node->val < qVal){
                node=node->right;
            }
            else if(node->val > pVal && node->val > qVal){
                node=node->left;
            }
            else{
                return node;
            }
        }
        return NULL;
    }
};


class Solution {
public:
    TreeNode* dfs(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root) return nullptr;
        
        if(root->val > p->val and root->val > q->val){
            return dfs(root->left,p,q);
        }
        if(root->val < p->val and root->val < q->val){
            return dfs(root->right,p,q);
        }
        
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        return dfs(root,p,q);
    }
};