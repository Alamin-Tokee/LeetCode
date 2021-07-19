//Time Complexity O(h)
//Space Complexity O(h)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(!root) return NULL;
         if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);
         if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
         return root;
	}
};


//Time Complexity O(h)
//Space Complexity O(h)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        
        if(root->val==p->val || root->val == q->val) return root;
        
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        
        if(l && r) return root;
        
        return l ? l : r;
	}
};


//Time Complexity O(2^h)
//Space Complexity O(h)
class Solution {
public:
    bool lca(TreeNode* root,TreeNode* a){
        if(!root) return false;
        if(root->val == a->val) return true;
        
        return lca(root->left,a) || lca(root->right,a);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root) return NULL;
        if(lca(root->left,p) && lca(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        if(lca(root->right,p) && lca(root->right,q)) return lowestCommonAncestor(root->right,p,q);
        
        return root;
    }
};

//Time Complexity O(h)
//Space Complexity O(1)
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