// https://leetcode.com/problems/sum-root-to-leaf-numbers/

class Solution {
public:
    void getSum(TreeNode* root, int &ans, int &sum){
        if(root->left == NULL && root->right == NULL){
            ans = ans + sum*10 + root->val;
            return;
        }

        sum = sum*10 + root->val;
        // cout<<"root->val "<<root->val<<endl;
        // cout<<"anish "<<sum<<endl;


        if(root->left){
            getSum(root->left, ans, sum);
        }

        if(root->right){
            getSum(root->right, ans, sum);
        }

        sum = sum/10;
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int ans = 0, sum = 0;
        getSum(root, ans, sum);

        return ans;
    }
};
