// https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int> , vector<string> > m;

        for(int i =0; i<strs.size(); i++){
            vector<int> freq(26);
            for(int j = 0; j<strs[i].length(); j++){
                freq[strs[i][j] - 'a']++;
            }
            m[freq].push_back(strs[i]);
        }

        vector<vector<string> > ans;

        for(auto i : m){
            ans.push_back(i.second);
        }

        return ans;
    }
};


// another method
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>map;
        for(string s : strs)
        {
            string key = s;
            sort(key.begin(),key.end());
            map[key].push_back(s);
        }
        vector<vector<string>>result;
        for(auto &pair : map)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
