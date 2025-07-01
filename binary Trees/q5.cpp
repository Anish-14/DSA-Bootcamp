// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/


class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        long long sum = 0;
        int cnt = 0;

        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();
            
            if(currNode == NULL){
                double avg = double(sum)/double(cnt);
                ans.push_back(avg);
                cnt = 0;
                sum = 0;
                if(!q.empty()){
                    q.push(NULL);
                }
                
                continue;
            }

            cnt++;
            sum += currNode->val;

            if(currNode->left){
                q.push(currNode->left);
            }
            if(currNode->right){
                q.push(currNode->right);
            }
        }

        return ans;
    }
};
