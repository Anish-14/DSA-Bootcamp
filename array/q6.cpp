// https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=problem-list-v2&envId=array
// median of two sorted arrays
// V.Imp

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int len1 = nums1.size(), len2 = nums2.size();
        int left = 0, right = len1;

        while (left <= right) {
            // cout<<"left and right is "<<left<<" "<<right<<endl;
            int part1 = (left + right) / 2;
            int part2 = (len1 + len2 + 1) / 2 - part1;
            // cout<<"part1 is "<<part1<<" part2 is "<<part2<<endl;

            int maxLeft1 = (part1 == 0) ? INT_MIN : nums1[part1 - 1];
            int minRight1 = (part1 == len1) ? INT_MAX : nums1[part1];
            int maxLeft2 = (part2 == 0) ? INT_MIN : nums2[part2 - 1];
            int minRight2 = (part2 == len2) ? INT_MAX : nums2[part2];
            // cout<<"maxL1 "<<maxLeft1<<" minR1 "<<minRight1<<" maxL2 "<<maxLeft2<<" minR2 "<<minRight2<<endl;
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((len1 + len2) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                right = part1 - 1;
            } else {
                left = part1 + 1;
            }
        }

        return 0.0; 
    }
};
