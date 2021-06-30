//Time Complexity O(n)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root) return NULL;
        if(root->val==p->val || root->val==q->val) return root;
        
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        
        if(left && right) return root;
        
        return left ? left : right;   
    }
};

//Time Complexity O(n)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root; 
        TreeNode *left = lowestCommonAncestor(root->left, p, q), *right = lowestCommonAncestor(root->right, p, q); 
        if (left && right) return root; 
        return left ? left : right; 
    }
};

//Time Complexity O(n*n)
class Solution {
public:
    bool isPresent(TreeNode* root,TreeNode* a){
    if(!root) return false;
    if(root->val==a->val) return true;
    return isPresent(root->left,a) || isPresent(root->right,a);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(isPresent(root->right,p) && isPresent(root->right,q)) return lowestCommonAncestor(root->right,p,q);
        if(isPresent(root->left,p) && isPresent(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};








//Exception
bool findPath(TreeNode* root,vector<TreeNode*>&path,int k){
	if(root==NULL) return false;

	path.push_back(root->key);

	if(root->key==k) return true;

	if(((root->left) && findPath(root->left,path,k)) ||(root->right && findPath(root->right, path, k))) return true;

	path.pop_back();

	return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	vector<TreeNode*>path1, path2;

	if(!findPath(root,path1,p) || !findPath(root,path2,q)) return -1;

	int i;
	for(int i=0;i<path1.size() && i < path2.size(); i++){
		if(path[i]!=path2[i]) break;
	}
	return path1[i-1];
}
