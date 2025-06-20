// https://leetcode.com/problems/maximum-performance-of-a-team/


// we will take k with the greatest effectiveness
// then we will iterate through the remaining vector, so if we find any better combination then we will save that in our answer
class Solution {
public:
    typedef pair<int, int> pp;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pp> combined;

        for(int i = 0; i < speed.size(); i++){
            combined.push_back({efficiency[i], speed[i]});
        }

        sort(combined.begin(), combined.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long result = 0, speedSum = 0;
        int mod = 1e9 + 7;

        for(int i = combined.size() - 1; i >= 0; i--){
            speedSum += combined[i].second;
            if(pq.size() == k){
                // top contains minSum so we will pop that
                speedSum -= pq.top();
                pq.pop();
            }
            pq.push(combined[i].second);
            result = max(result, speedSum * combined[i].first);
        }

        return result % mod;
    }
};
