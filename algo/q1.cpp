// https://leetcode.com/problems/move-zeroes/description/
// move zeros to end

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZero = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[nonZero]);
                nonZero++;
            }
        }
    }
};
