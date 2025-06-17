// https://leetcode.com/problems/ransom-note/description/


// obviously without map this would become an optimal method by using a vector of 26 lengtho storing the char's freq
// but this was a hashmap's questionare so I wanted to solve it using hashmap
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
