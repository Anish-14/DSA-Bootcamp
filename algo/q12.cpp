// https://leetcode.com/problems/find-k-closest-elements/description/


// this solution is better because for finding pivot it uses binary search instead of linear search and that's better
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = -1, r = n;
        int pivot = 0;
        vector<int> ans;

        // Find closest on left (<= x)
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (arr[mid] <= x) {
                l = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Find closest on right (>= x)
        low = 0, high = n - 1;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (arr[mid] >= x) {
                r = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Determine pivot
        if (l >= 0 && r < n) {
            if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                pivot = l;
            } else {
                pivot = r;
            }
        } else if (l >= 0) {
            pivot = l;
        } else {
            pivot = r;
        }

        ans.push_back(arr[pivot]);
        k--;

        // Expand outward
        int left = pivot - 1, right = pivot + 1;
        while (k > 0) {
            if (left >= 0 && right < n) {
                if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                    ans.push_back(arr[left--]);
                } else {
                    ans.push_back(arr[right++]);
                }
            } else if (left >= 0) {
                ans.push_back(arr[left--]);
            } else if (right < n) {
                ans.push_back(arr[right++]);
            }
            k--;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
