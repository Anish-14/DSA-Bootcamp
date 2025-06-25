// https://leetcode.com/problems/minimum-positive-sum-subarray/description/


class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), mini = INT_MAX;
        for (int len = l; len <= r; ++len) {
            if (len > n) break;
            int sum = 0;
            for (int i = 0; i < len; ++i){
                sum += nums[i];
            } 
            if (sum > 0) {
                mini = min(mini, sum);
            }
            for (int i = len; i < n; ++i) {
                sum += nums[i] - nums[i - len];
                if (sum > 0){
                    mini = min(mini, sum);
                } 
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};
