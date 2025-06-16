// https://leetcode.com/problems/combination-sum-ii/

class Solution {
    void combination(int i, int target, vector<int>& candidates, vector<int>& ans, vector<vector<int>>& comb) {
        if (target == 0) {
            comb.push_back(ans);
            return;
        }

        if (i >= candidates.size() || target < 0) return;

        // inclusion
        ans.push_back(candidates[i]);
        combination(i + 1, target - candidates[i], candidates, ans, comb);
        ans.pop_back();

        // exclusion
        int j = i + 1;
        while (j < candidates.size() && candidates[j] == candidates[i]) j++;

        combination(j, target, candidates, ans, comb);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        vector<vector<int>> comb;
        combination(0, target, candidates, ans, comb);
        return comb;
    }
};
