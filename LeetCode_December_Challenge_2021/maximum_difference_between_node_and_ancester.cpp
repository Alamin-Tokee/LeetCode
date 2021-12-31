//Time Complexity O(2^n);
//Space Complexity O(2^n)
class Solution {
public:
    int diff=INT_MIN;
    void dfs(TreeNode* root,int &val){
        if(!root) return;
        
        diff=max(diff,abs(val-root->val));
        
        dfs(root->left,val);
        dfs(root->right,val);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        
        dfs(root,root->val);
        
        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);
        return diff;
    }
};

//Time Complexity O(n)
//Space Complexity O(n) // Consider recursive stack
class Solution {
public:
    int diff=INT_MIN;
    void dfs(TreeNode* root,int mx,int mn){
        if(!root) return;
        
        mn=min(mn,root->val);
        mx=max(mx,root->val);
        diff=max(diff,abs(mx-mn));
        
        dfs(root->left,mx,mn);
        dfs(root->right,mx,mn);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int mn=INT_MAX;
        int mx=INT_MIN;
        dfs(root,mx,mn);
        
        return diff;
    }
};

//Time Complexity O(N)
//Space complexity O(N+N)
class Solution{
public:
int maxAncestorDiff(TreeNode* root) {
    int res = 0;
    queue<pair<int,int>> val;
    val.push(make_pair(root->val, root->val));
	
    queue<TreeNode *> bfs;
    bfs.push(root);
    while (bfs.empty() == false) {
        TreeNode *curr = bfs.front();
        bfs.pop();
        
        pair<int, int> p = val.front();
        val.pop();
        int currmin = p.first;
        int currmax = p.second;
        res = max(res, currmax - currmin);
        
        if (curr->left != nullptr) {
            bfs.push(curr->left);
			
            int newmin = min(currmin, curr->left->val);
            int newmax = max(currmax, curr->left->val);
            val.push(make_pair(newmin, newmax));
        }
        if (curr->right != nullptr) {
            bfs.push(curr->right);
			
            int newmin = min(currmin, curr->right->val);
            int newmax = max(currmax, curr->right->val);
            val.push(make_pair(newmin, newmax));
        }
    }
    return res;
}
};
