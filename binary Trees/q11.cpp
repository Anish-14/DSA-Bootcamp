// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
public:
    int getIndex(vector<int> &inorder, int val){
        int index = -1;
        for(int i = 0; i<inorder.size(); i++){
            if(inorder[i] == val){
                index = i;
                break;
            }
        }
        return index;
    }

    TreeNode* build(vector<int> &preorder, int &currIndex, vector<int>&inorder,
                int start, int end, int n){
        if(start > end || currIndex > n){
            return NULL;
        }

        // make the current node
        int val = preorder[currIndex++];
        TreeNode* root = new TreeNode(val);

        // get the index
        int index = getIndex(inorder, val);

        // call for left && right node
        root->left = build(preorder, currIndex, inorder, start, index-1, n);
        root->right = build(preorder, currIndex, inorder, index+1, end, n);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int currIndex = 0;
        return build(preorder, currIndex, inorder, 0, n-1, n);
    }
};
