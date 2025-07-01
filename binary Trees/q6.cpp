// https://leetcode.com/problems/invert-binary-tree/description/


class Solution {
public:
    void invert(TreeNode* root, TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL){
            return ;
        }

        if(left != NULL){
            invert(left, left->left, left->right);
        }
        if(right != NULL){
            invert(right, right->left, right->right);
        }
        
        root->left = right;
        root->right = left;

    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }

        invert(root, root->left, root->right);    

        return root;
    }
};
