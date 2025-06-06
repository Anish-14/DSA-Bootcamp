// https://leetcode.com/problems/majority-element-ii/
// majority element

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int major1 = 0;
        int major2 = 0;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();

        // we are finding the candidate for our answers
        for(int i = 0; i<n; i++){
            if(nums[i] == major1){
                count1++;
            }
            else if(nums[i] == major2){
                count2++;
            }
            else if(count1 == 0){
                major1 = nums[i];
                count1++;
            }
            else if(count2 == 0){
                major2 = nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

        // now we will count our candidate's freq
        count1 = 0;
        count2 = 0;

        for(int i = 0; i<n; i++){
            if(nums[i] == major1){
                count1++;
            }
            else if(nums[i] == major2){
                count2++;
            }
        }

        vector<int> ans;
        if(count1 >= n/3 + 1){
            ans.push_back(major1);
        }
        if(count2 >= n/3 + 1){
            ans.push_back(major2);
        }

        return ans;
    }
};
