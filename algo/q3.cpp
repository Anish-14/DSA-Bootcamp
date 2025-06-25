// https://leetcode.com/problems/maximum-average-subarray-i/description/


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i = 0; i<k; i++){
            sum += nums[i];
        }

        double avg = sum/k;

        for(int i = 1; i<=nums.size()-k; i++){
            sum -= nums[i-1];
            sum += nums[i+k-1];
            double temp = sum/k;
            avg = max(avg, temp);
        }
        return avg;
    }
};
