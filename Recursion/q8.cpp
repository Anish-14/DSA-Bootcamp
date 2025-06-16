// https://leetcode.com/problems/combination-sum/description/


class Solution {
public:
    void print(vector<int> &temp){
        for(int i = 0; i<temp.size(); i++){
            cout<<temp[i]<<" ";
        }cout<<endl;
    }
    void solve(vector<int>& candidates, set<vector<int> > &ans, vector<int> temp,
        int &sum, int target, int idx){
        // base cases to return
        if(idx >= candidates.size() || sum > target){
            return ;
        }
        // save the answer
        if(sum == target){
            ans.insert(temp);
        }

        
        // include and don't go forward, as we can include duplicate answers
        sum += candidates[idx];
        temp.push_back(candidates[idx]);
        // print(temp);
        // cout<<sum<<endl;
        solve(candidates, ans, temp, sum , target, idx);

        // include and go forward
        solve(candidates, ans, temp, sum , target, idx+1);

        // exclude
        sum -= candidates[idx];
        temp.pop_back();
        solve(candidates, ans, temp, sum, target, idx+1);

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        vector<int> temp;
        set<vector<int>> ans;
        int idx = 0;
        solve(candidates,ans,temp,sum,target,idx);

        vector<vector<int>> res;
        for(auto i : ans){
            res.push_back(i);
        }

        return res;
    }
};
