// https://leetcode.com/problems/valid-palindrome/description/?envType=problem-list-v2&envId=string
// valid pallindrome

class Solution {
public: 
    void toSmallChar(string &s){
        int n = s.length();
        for(int i = 0; i<n; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = s[i] - 'A' + 'a';
            }
        }
    }

    bool isPalindrome(string s) {
        int start = 0; 
        int end = s.length() - 1;

        toSmallChar(s);

        while(start < end){
            if(!(s[start] >= 'a' && s[start] <= 'z' || s[start] >= '0' && s[start] <= '9')){
                start++;
                continue;
            }
            else if(!(s[end] >= 'a' && s[end] <= 'z' || s[end] >= '0' && s[end] <= '9')){
                end--;
                continue;
            }
            else if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
