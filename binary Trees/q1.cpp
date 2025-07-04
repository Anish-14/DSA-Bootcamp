// https://leetcode.com/problems/same-tree/description/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL || q == NULL){
            return false;
        }
        if(p->val != q->val){
            return false;
        }

        bool isLeft = isSameTree(p->left, q->left);
        bool isRight = isSameTree(p->right, q->right);

        return isLeft && isRight;
    }
};
