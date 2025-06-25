// https://leetcode.com/problems/contains-duplicate-ii/description/


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mapping;

        for(int i = 0; i<n; i++){
            if(mapping.find(nums[i]) != mapping.end()){
                if(i - mapping[nums[i]] <=k ){
                    return true;
                }
            }
            mapping[nums[i]] = i;
        }

        return false;
    }
};
