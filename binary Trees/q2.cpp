// https://leetcode.com/problems/maximum-depth-of-binary-tree/


class Solution {
public:
    int Depth(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = Depth(root->left);
        int right = Depth(root->right);

        return max(left, right) + 1;
    }
    
    int maxDepth(TreeNode* root) {
        return Depth(root);
    }
};
