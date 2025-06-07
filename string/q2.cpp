// Valid anagram
// https://leetcode.com/problems/valid-anagram/description/

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26,0);
        int n = s.length();
        int m = t.length();
        if(m != n){
            return false;
        }

        for(int i = 0; i<n; i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(int i = 0; i<26; i++){
            if(count[i] != 0){
                return false;
            }
        }

        return true;
    }
};
