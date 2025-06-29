// https://leetcode.com/problems/binary-tree-inorder-traversal/description/
// inorder traversal of binary tree without recursion (using stack)


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;

        while (root != nullptr || !stack.empty()) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }

            root = stack.top();
            stack.pop();
            res.push_back(root->val);
            root = root->right;
        }

        return res;        
    }
};
