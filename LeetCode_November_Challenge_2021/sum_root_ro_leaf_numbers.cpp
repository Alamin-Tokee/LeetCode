class Solution {
public:

    int ans=0;
    void dfs(TreeNode* root,int sum){
        if(!root) return;
        sum=sum*10+root->val;
        if(!root->left && !root->right){
            ans+=sum;
            return;
        }
        dfs(root->left,sum);
        dfs(root->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        dfs(root,0);
        
        return ans;
    }
};


class Solution {
public:
    int ans = 0, cur = 0;
    
    void solve(TreeNode* root) {
        if(!root) return;
        cur = cur * 10 + root->val;
        if(!root->left and !root->right) ans += cur;
        solve(root->left);
        solve(root->right);
        cur /= 10;
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        solve(root);
        return ans;
    }
};


class Solution {
public:
	int sumNumbersHelper(TreeNode* root, int currSum){
		if(!root){
			return 0;
		}
		currSum = currSum * 10 + root -> val;
		if(!(root -> left) && !(root -> right)){
			return currSum;
		}
		return sumNumbersHelper(root -> left, currSum) + sumNumbersHelper(root -> right, currSum);
	}
	int sumNumbers(TreeNode* root) {
		return sumNumbersHelper(root, 0);
	}
};


class Solution {
public:
    int sumNumbers(TreeNode* root) {
        stack<TreeNode*> nodes;
        if (!root) return 0;
        
        int total = 0;
        int current = 0;
        TreeNode* last = nullptr;
        while (root || !nodes.empty()){
            if (root){
                nodes.push(root);
                current *= 10;
                current += root->val;
                root = root->left;
            }
            else{
                root = nodes.top();
                if (root->right && root->right != last){
                    root = root->right;
                }
                else {
                     nodes.pop();
                     last = root;
                     // only add sum of leaf node
                     if (root->right == nullptr && root->left == nullptr)
                        total += current;
                     current /= 10;
                     root = nullptr;
                }
            }
          }
         return total;
    }
};

