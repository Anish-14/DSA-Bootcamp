// https://leetcode.com/problems/longest-consecutive-sequence/description/

// O(n*logn) && O(n)
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


// this is better solution than the above
// O(n) && O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=1;
        }
        for (auto &x: m)
        {
            int ele=x.first;
            if(x.second==0)continue;
            int sum=1;
            int y=ele;
            while(1)
            {   
                y++;
                auto it=m.find(y);
                if(it==m.end())break;
                else
                {
                    sum++;
                    m.erase(it);
                }
            }
                y=ele;
            while(1)
            {   
                y--;
                auto it=m.find(y);
                if(it==m.end())break;
                else
                {
                    sum++;
                    m.erase(it);
                }
            }
            m[ele]=0;

            ans=max(ans,sum);
            
        }
        return ans;
    }
};

