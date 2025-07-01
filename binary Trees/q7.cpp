// https://leetcode.com/problems/root-equals-sum-of-children/

class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(root->val == root->left->val + root->right->val){
            return 1;
        }
        return 0;
    }
};
