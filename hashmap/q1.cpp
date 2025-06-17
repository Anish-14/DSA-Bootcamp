// https://leetcode.com/problems/ransom-note/description/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(int i = 0; i<magazine.length(); i++){
            m[magazine[i]]++;
        }

        for(int i = 0; i<ransomNote.length(); i++){
            if(m[ransomNote[i]] == 0){
                return false;
            }
            m[ransomNote[i]]--;
        }

        return true;
    }
};
