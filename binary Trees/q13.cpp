// https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    int solve(TreeNode* root, int &res){
        if(!root){
            return 0;
        }

        // take the left and right max sums
        int left = max(0, solve(root->left, res));
        int right = max(0, solve(root->right, res));

        res = max(res, left + right + root->val);

        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        solve(root, res);

        return res;
    }
};
