// https://leetcode.com/problems/create-maximum-number/


class Solution {
public:
    vector<int> maxnum(vector<int>& nums, int k) {
        vector<int> res;
        int drop = nums.size() - k;
        for (int num : nums) {
            while (!res.empty() && drop > 0 && res.back() < num) {
                res.pop_back();
                drop--;
            }
            res.push_back(num);
        }
        res.resize(k); // In case we didn’t drop enough
        return res;
    }

    // Function to merge two sequences into the max lexicographical number
    string merge(vector<int>& a, vector<int>& b, int k) {
        string s = "";
        int i = 0, j = 0;
        while (s.size() < k) {
            // Compare remaining suffixes: a[i:] vs b[j:]
            if (lexicographical_compare(a.begin()+i, a.end(), b.begin()+j, b.end())) {
                s += (b[j++] + '0');
            } else {
                s += (a[i++] + '0');
            }
        }
        return s;
    }

        vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
            int n = nums1.size(), m = nums2.size();
            string mx = "";
            for(int i = 0; i <= k && i <= n; i++){
                if((k-i) > m) continue; //If we are taking i size of largest array from nums1 then are we capable of building k-i size of largest array from num2 .
                vector<int> n1 = maxnum(nums1, i);
                vector<int> n2 = maxnum(nums2, k-i);
                string s = merge(n1, n2, k);
                mx = max(mx, s);
            }
            
            vector<int> res;
            for(int i = 0; i < mx.size(); i++) 
                res.push_back(mx[i] - '0');
            return res;
    }
};
