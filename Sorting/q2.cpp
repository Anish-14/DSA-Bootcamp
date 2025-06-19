// https://leetcode.com/problems/find-the-difference/description/


class Solution {
public:
    char findTheDifference(string s, string t) {
        int sumt = 0;
        for(int i = 0; i<t.length(); i++){
            sumt += t[i] - 'a';
        }

        int sums = 0;
        for(int i = 0; i<s.length(); i++){
            sums += s[i] - 'a';
        }

        char ch = sumt - sums + 'a';
        return ch;
    }
};
