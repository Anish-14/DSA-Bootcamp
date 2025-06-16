// https://leetcode.com/problems/subsets-ii/description/
// this method is known as forward inclusion

class Solution {
public:

    void solve(vector<vector<int>> &ans, vector<int>& nums, vector<int>& temp, int index) {
        ans.push_back(temp); // push as soon as you reach this node (before branching)

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue; // skip duplicates
            temp.push_back(nums[i]);
            solve(ans, nums, temp, i + 1);
            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, nums, temp, 0);

        return ans;
    }
};



// there's another recursive method which stores all the subsets but not in the order the question wanted
void solve(vector<vector<int>> &ans, vector<int>& nums, vector<int> temp, int index) {
    // we don't have to include a base case for index greater the array's size as it will never
    // go par that due to this base case
    if(index == nums.size()) {
        ans.push_back(temp);
        return;
    }

    // inclusion
    temp.push_back(nums[index]);
    solve(ans, nums, temp, index+1);

    // exclusion
    temp.pop_back();
    solve(ans, nums, temp, index+1);
}




