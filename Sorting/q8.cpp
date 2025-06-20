// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/


// very good problem
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());

        // this map stores the last index and the profit earned, and this will only entries with bigger profit than the previous one
        map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            // upper_bound --> will find the key just larger than the given, if Not then it will pass .end() iterator
            // prev --> will give you the prev key,value pair of passed iterator
            // here we're finding the job whose endTime is just smaller then or equal to our current startTime and then we'll add our curr profit
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            // if it's profit is bigger compared to the last key,value pair in map. this is ordered_map so everything is stored in a good manner
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        // will return our last value as it contains the largest profit 
        return dp.rbegin()->second;
    }
};
