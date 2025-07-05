// https://leetcode.com/problems/maximum-sum-circular-subarray/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0];
        int minSum = nums[0];
        int currMaxSum = nums[0];
        int currMinSum = nums[0];
        int totalSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // Kadane's algorithm for maximum sum
            // Either extend previous subarray or start a new one
            currMaxSum = max(currMaxSum + nums[i], nums[i]);
            maxSum = max(maxSum, currMaxSum);
            
            // Kadane's algorithm for minimum sum
            // Either extend previous subarray or start a new one
            currMinSum = min(currMinSum + nums[i], nums[i]);
            minSum = min(minSum, currMinSum);
            
            // Calculate the total sum of all elements
            totalSum += nums[i];
        }
        
        // The circular sum is the total sum minus the minimum subarray sum
        int circularSum = totalSum - minSum;
        
        // Edge case: if all numbers are negative, then maxSum will be negative
        // and circularSum will be 0 (empty subarray), but we need to return the max negative value
        if (circularSum == 0) {
            return maxSum;
        }
        
        // Return the maximum of the regular subarray sum and the circular subarray sum
        return max(maxSum, circularSum);
    }
};
