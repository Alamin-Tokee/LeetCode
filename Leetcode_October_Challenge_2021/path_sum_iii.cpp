class Solution {
public:
    int count=0;
    void dfs(TreeNode* root,int &target,int sum){
        if(!root) return;
        sum+=root->val;
        if(sum==target) count++;
        dfs(root->left,target,sum);
        dfs(root->right,target,sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        
        dfs(root,targetSum,0);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        
        return count;
    }
};


class Solution {
public:
    int count=0;
    void dfs(TreeNode* root,int &target,int sum){
        if(!root) return;
        sum+=root->val;
        if(sum==target) count++;
        dfs(root->left,target,sum);
        dfs(root->right,target,sum);
    }
    
    void path(TreeNode* root,int targetSum){
        if(!root) return;
        dfs(root,targetSum,0);
        path(root->left,targetSum);
        path(root->right,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        path(root,targetSum);
        return count;
    }
};


class Solution {
public:
    unordered_map<int, int> map;
    int count = 0;
    
    void countPathSum(TreeNode* root, int target, int sum){
        if(!root)
            return;
        sum += root->val;        
        if(sum == target)
            count++;
        if(map.find(sum - target) != map.end())         
            count += map[sum - target];
        map[sum]++;
        countPathSum(root->left, target, sum);
        countPathSum(root->right, target, sum);
        map[sum]--;  
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        countPathSum(root, targetSum, 0);
        return count;
    }
};


class Solution {
public:
    void path(TreeNode* ptr,int t,int& count){
        bool flag = false;
        if(ptr->val == t) {
            count++;
        }
        if(ptr->left) {
            path(ptr->left,t-ptr->val,count);
        }
        if(ptr->right) {
            path(ptr->right,t-ptr->val,count);
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        queue<TreeNode* > q;
        q.push(root); int count = 0;
        while(!q.empty()){
            TreeNode* tmp = q.front();
            path(tmp,targetSum,count);
            q.pop();
            
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        
        return count;
    }
};


int pathSum(TreeNode* root, int target) {

  if(!root)
    return 0;
  
  return find(root,0,target) + pathSum(root->left,target) + pathSum(root->right,target);
}

int find(TreeNode* root,int sum,int& target){

     if(!root)
        return 0;

     sum+=root->val;

     if(sum==target)
         return 1+ find(root->left,sum,target) + find(root->right,sum,target);
     else
         return find(root->left,sum,target) + find(root->right,sum,target);
    
} 


class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        return helper(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
    
    int helper(TreeNode *root, int targetSum) {
        if (!root)
            return 0;
        return (root->val == targetSum)  + helper(root->left, targetSum - root->val) +  helper(root->right, targetSum - root->val);         
    }
};