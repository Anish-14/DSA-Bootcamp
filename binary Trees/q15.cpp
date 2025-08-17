//https://leetcode.com/problems/binary-tree-cameras/

// first approach
class Solution {
public:
    int ans=0;
    unordered_set<TreeNode*>covered;
    void dfs(TreeNode* root,TreeNode* parent){
        if(!root) return;
        
        dfs(root->left,root);
        dfs(root->right,root);
        
        if((parent==NULL && covered.find(root)==covered.end()) ||
           (covered.find(root->left)==covered.end()) || 
           (covered.find(root->right)==covered.end())){
            ans++;
            
            // Put Camera
            covered.insert(parent);
            covered.insert(root);
            covered.insert(root->left);
            covered.insert(root->right);
        }
    }
    int minCameraCover(TreeNode* root) {
        covered.clear();
        
        // Read Above NOTE
        covered.insert(NULL);
        ans=0;
        
        dfs(root,NULL);
        return ans;
    }
};



// Second Approach --> Optimised version 
class Solution {
private:
    int cameraCount = 0;
public:
    int dfs(TreeNode* root){
        if(root == NULL){
            return 1;       // 1 represent that this node is covered
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        if(left == 2 || right == 2){
            cameraCount++;
            return 0;
        }
        if(left == 0 || right == 0){
            return 1;
        }

        return 2;
    }
    int minCameraCover(TreeNode* root) {
        if(dfs(root) == 2){
            cameraCount++;
        }

        return cameraCount;
    }
};
