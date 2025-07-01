// https://leetcode.com/problems/symmetric-tree/

class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL){
            return 1;
        }
        if(left == NULL || right == NULL){
            return 0;
        }

        if(left->val != right->val){
            return 0;
        }

        return isMirror(left->right, right->left) && isMirror(left->left, right->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return 1;
        }

        return isMirror(root->left, root->right);
    }
};
