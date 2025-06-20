// https://leetcode.com/problems/number-of-flowers-in-full-bloom/


class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> start, end;
        for (auto& t : flowers)
            start.push_back(t[0]), end.push_back(t[1]);
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> res;
        for (int t : persons) {
            // upper_bound gives the iterator but subtracting .begin() gives the index
            // upper_bound gives ele > given and lower_bound gives ele >= given
            int started = upper_bound(start.begin(), start.end(), t) - start.begin();
            int ended = lower_bound(end.begin(), end.end(), t) - end.begin();
            // started notes how many flowers started till here and ended notes how many ended
            // hence there diff is our answer
            res.push_back(started - ended);
        }
        return res;
    }
};
