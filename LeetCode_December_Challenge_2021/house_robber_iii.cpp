
//Time Complexity(2^N)
//Space Complexity(H)
class Solution {
public:
    int dfs(TreeNode* root){
        if(!root) return 0;
        if(root->left){
            root->val+=dfs(root->left->left)+dfs(root->left->right);
        }
        if(root->right){
            root->val+=dfs(root->right->left)+dfs(root->right->right);
        }
        
        return max(root->val,dfs(root->left)+dfs(root->right));
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        
        return dfs(root);
    }
};


//Time Complexity(2^N)
//Space Complexity(H)
class Solution {
public:
    int rob(TreeNode* root) {
        return root ? max(root->val + (root->left ? rob(root->left->left) + rob(root->left->right) : 0) + (root->right ? rob(root->right->left) + rob(root->right->right) : 0), rob(root->left) + rob(root->right)) : 0;
    }
};

//Time Complexity O(N)
//Space Complexity O(N)

class Solution {
public:
    int dfs(TreeNode* node,unordered_map<TreeNode*,int>&mem){
        if(!node) return 0;
        if(mem.count(node)!=0) return mem[node];
        
        int maxWithNode=node->val;
        if(node->left!=nullptr){
            maxWithNode+=dfs(node->left->left,mem)+dfs(node->left->right,mem);
        }
        if(node->right!=nullptr){
            maxWithNode+=dfs(node->right->left,mem)+dfs(node->right->right,mem);
        } 
        int maxWithoutNode=dfs(node->left,mem)+dfs(node->right,mem);
        
        return mem[node]=max(maxWithNode,maxWithoutNode);
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        unordered_map<TreeNode*,int>mem;
        return dfs(root,mem);
    }
};










