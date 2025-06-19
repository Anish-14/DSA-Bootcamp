// https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp;
        int n = nums1.size();
        int m = nums2.size();

        for(int i = 0; i<n; i++){
            mp[nums1[i]]++;
        }

      for(int i = 0; i<m; i++){
            if(mp[nums2[i]] > 0){
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }

        return ans;
    }
};
