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


// another method for it 

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftmax = 0, rightmax = 0;
        int total = 0;

        while(left < right){
            if(height[left] < height[right]){
                leftmax = max(leftmax, height[left]);
                total += (leftmax - height[left]);
                left++;
            }
            else{
                rightmax = max(rightmax, height[right]);
                total += (rightmax - height[right]);
                right--;
            }
        }
        return total;
    }
};
