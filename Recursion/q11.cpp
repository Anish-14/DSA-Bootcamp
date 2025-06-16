// https://leetcode.com/problems/combination-sum-iii/description/


class Solution {
public:
    void solve(int k, int target, vector<vector<int>> &ans, vector<int> &temp, int num){
        if(k == 0 && target == 0){
            ans.push_back(temp);
            return;
        }
        // agar donon nhi hai but ek bhi hai then return without saving the answer
        if(k == 0 || target == 0){
            return;
        }
        
        for(int i = num; i<= target && i<=9; i++){
            temp.push_back(i);
            solve(k-1,target-i,ans,temp,i+1);
            temp.pop_back();
        }

        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        // sum of first k words se to bada hona chahiye atlease
        if(n < k*(k+1)/2){
            return ans;
        }
        solve(k,n,ans,temp,1);

        return ans;
    }
};
