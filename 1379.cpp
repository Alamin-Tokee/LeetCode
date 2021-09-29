/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* clone_result;
    void dfs(TreeNode* node,TreeNode* target){
        if(!node) return;
        
        if(node->val==target->val){
            clone_result=node;
            return;
        }
        
        dfs(node->left,target);
        dfs(node->right,target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!cloned) return NULL;
        clone_result=cloned;
        dfs(cloned,target);
        
        return clone_result;
    }
};

class Solution {
public:
    TreeNode* clone_result;
    void getNode(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original==NULL)
            return;
        if(original==target){
            clone_result=cloned;
            return;
        }
        getNode(original->left, cloned->left, target);
        getNode(original->right, cloned->right, target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        clone_result=cloned;
        getNode(original, cloned, target);
        return clone_result;
    }
};


class Solution {
  public:
    TreeNode * getTargetCopy(TreeNode * original, TreeNode * cloned, TreeNode * target) {
      if (!cloned) return NULL;
      if (cloned -> val == target -> val) return cloned;

      if (getTargetCopy(original -> left, cloned -> left, target))
        return getTargetCopy(original -> left, cloned -> left, target);
      else
        return getTargetCopy(original -> right, cloned -> right, target);
    }
}


class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original) return nullptr;
        if (original == target) return cloned;
        return max(getTargetCopy(original->left, cloned->left, target),
            getTargetCopy(original->right, cloned->right, target));
    }
};


class Solution {
public:
    TreeNode * getTargetCopy(TreeNode * original, TreeNode * cloned, TreeNode * target) {
        if(!cloned) return NULL;
        int sum=0;
        queue<TreeNode*>q;
        q.push(cloned);
        while(!q.empty()){ 
            auto p=q.front();   
            q.pop();  
            if(p->val==target->val) return p;    
            if(p->left) q.push(p->left);   
            if(p->right) q.push(p->right);
        }
        return NULL;
    }
};
