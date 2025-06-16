// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    void print(vector<int> &temp){
        for(int i = 0; i<temp.size(); i++){
            cout<<temp[i]<<" ";
        }cout<<endl;
    }
    void solve(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp,
               int target, int idx) {
        if (target == 0) {
            print(temp);
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue; // skip duplicates, as they're covered in the recursive calls
            if (candidates[i] > target) break; // pruning

            temp.push_back(candidates[i]);
            solve(candidates, ans, temp, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, ans, temp, target, 0);
        return ans;
    }
};
