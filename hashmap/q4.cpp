// https://leetcode.com/problems/longest-consecutive-sequence/description/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,bool> m;         // val, present
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]] = 1;
        }

        int maxi = 0;
        int currLen = 0;
        int prev = 0;

        for(auto i : m){
            // cout<<i.first<<" "<<i.second<<endl;
            if(currLen == 0){
                currLen = 1;
                prev = i.first;
                maxi = max(maxi, currLen);
                continue;
            }

            if(i.first == prev + 1){
                currLen++;
            }
            else{
                currLen = 1;
            }
            prev = i.first;
            maxi = max(maxi, currLen);
            // cout<<"maxi till now "<<maxi<<endl;
        }

        return maxi;
    }
};
