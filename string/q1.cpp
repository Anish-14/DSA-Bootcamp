// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// find the index of first occurance in a string
// you can think of KMP algo

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        bool isFound;
        for(int i = 0; i<=n-m; i++){
            isFound = true;
            for(int j = 0; j<m; j++){
                if(haystack[i+j] != needle[j]){
                    isFound = false;
                }
            }
            if(isFound){
                return i;
            }
        }

        return -1;
    }
};
