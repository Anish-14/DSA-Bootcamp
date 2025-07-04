// https://leetcode.com/problems/trapping-rain-water/


// a beautiful problem and not that har but important
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0)
            return 0;
        vector<int> leftmax(n), rightmax(n);

        // filling leftmax;
        leftmax[0] = height[0];
        for(int i = 1; i<n; i++){
            leftmax[i] = max(leftmax[i-1], height[i]);
        }

        // filling rightmax
        rightmax[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--){
            rightmax[i] = max(rightmax[i+1], height[i]);
        }

        // measuring the water
        int total = 0;
        for(int i = 0; i<n; i++){
            total += min(rightmax[i], leftmax[i]) - height[i];
        }

        return total;
    }
};
