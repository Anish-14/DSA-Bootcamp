// https://leetcode.com/problems/subarray-sum-equals-k/
// Subarray sum equals k
// subarray is contiguous allocation of memory in the array
// For example, in [1, 2, 3], valid subarrays are:
	// •	[1], [2], [3]
	// •	[1, 2], [2, 3]
	// •	[1, 2, 3]

// But [1, 3] is not a subarray (not contiguous).


But [1, 3] is not a subarray (not contiguous).

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> subNum;
        subNum[0] = 1;
        int total = 0, count = 0;

        for (int n : nums) {
            total += n;

            if (subNum.find(total - k) != subNum.end()) {
                count += subNum[total - k];
            }

            subNum[total]++;
        }

        return count;

    }
};
