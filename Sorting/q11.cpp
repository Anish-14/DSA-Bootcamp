// question --> https://leetcode.com/problems/power-of-heroes/description/
// solution's article  --> https://leetcode.com/problems/power-of-heroes/solutions/3520233/c-java-python-sort-and-enumerate-each-maximum-value/


class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        long long res = 0, s = 0, base = 1e9 + 7;
        sort(nums.begin(), nums.end());
        for (int x: nums) {
            res = (res + (s + x) * x % base * x % base) % base;
            s = (s * 2 + x) % base;
        }
        return res;
    }
};
