// https://leetcode.com/problems/path-sum-iii/

class Solution {
public:
    int ans = 0;
    // function to get the sum from the root if it is there
    void countPath(TreeNode* root, long sum){
        if(!root)   return ;
        if(root->val == sum)    ans++;
        countPath(root->left, sum-root->val);
        countPath(root->right, sum-root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        // start your journey from every possible node
        if(root){
            countPath(root, long(targetSum));
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};
