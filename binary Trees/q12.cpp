// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }

        bool leftToRight = 1;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);

            for(int i = 0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();

                int index = leftToRight ? i : size-1-i;
                temp[index] = curr->val;

                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);
            }

            leftToRight = !leftToRight;
            ans.push_back(temp);
        }

        return ans;
    }
};
