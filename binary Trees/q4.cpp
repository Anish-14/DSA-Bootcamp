// https://leetcode.com/problems/diameter-of-binary-tree/description/

class Solution {
public:
    pair<int,int> dia(TreeNode* root){
        if(root == NULL){
            return make_pair(0,0);
        }

        pair<int,int> leftAns = dia(root->left);
        pair<int,int> rightAns = dia(root->right);

        pair<int,int> ans;
        ans.first = max(leftAns.first, rightAns.first) + 1;
        ans.second = max(max(leftAns.first + rightAns.first, leftAns.second), rightAns.second);

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return dia(root).second;
    }
};
