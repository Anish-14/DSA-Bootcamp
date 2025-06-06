// sort 0,1,2
// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int zero = -1;
        int two = n;
        int curr = 0;

        while(curr < two && curr > zero){
            if(nums[curr] == 0){
                swap(nums[curr],nums[zero+1]);
                zero++;
                curr++;
            }
            else if(nums[curr] == 1){
                curr++;
            }
            else{
                swap(nums[curr],nums[two-1]);
                two--;
            }
        }
    }
};
