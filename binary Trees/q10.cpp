// https://leetcode.com/problems/longest-univalue-path/

class Solution {
public:
    int maxi = 0;
    int dfs(TreeNode* root){
        if(!root)   return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);

        int leftVal = 0, rightVal = 0;

        if(root->left && root->left->val == root->val){
            leftVal = left;
        }
        if(root->right && root->right->val == root->val){
            rightVal = right;
        }

        maxi = max(maxi, leftVal + rightVal + 1);
        return max(leftVal, rightVal) + 1;
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return maxi>0 ? maxi-1: 0;
    }
};
