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

         // this statement is unnecessary, see the optimised code for better understanding
        // there should be only two calls
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



// the best solution
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int target, int index,
                   vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0 || index >= candidates.size()) return;

        // Include the current number (can use again)
        current.push_back(candidates[index]);
        backtrack(candidates, target - candidates[index], index, current, result);
        current.pop_back();

        // Skip to next number
        backtrack(candidates, target, index + 1, current, result);
    }
};

