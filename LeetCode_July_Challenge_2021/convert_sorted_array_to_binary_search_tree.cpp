class Solution {
public:
    TreeNode* arrayToBST(vector<int>& nums, int l, int r){
        
        if(l > r) return NULL;
        
        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = arrayToBST(nums, l, mid - 1);
        root->right = arrayToBST(nums, mid+1, r);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return arrayToBST(nums, 0, nums.size()-1);
        
    }
};