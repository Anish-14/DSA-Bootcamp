// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/


class Solution {
public:
    void solve(vector<string> &ans, unordered_map<char, string> &mp, string temp, string digits, int index){
        if(index == digits.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i<mp[digits[index]].length(); i++){
            temp.push_back(mp[digits[index]][i]);
            solve(ans, mp, temp, digits, index + 1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0){
            return ans;
        }
        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        solve(ans, mp, "", digits, 0);

        return ans;
    }
};
