// https://leetcode.com/problems/repeated-substring-pattern/description/?envType=problem-list-v2&envId=string
// repeated substring pattern
// writing this line to learn github, please ignore this line
// O(n^2) && O(1)

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                string repeated = "";
                for (int j = 0; j < n / i; j++) {
                    repeated += s.substr(0, i);
                }
                if (repeated == s) {
                    return true;
                }
            }
        }
        return false;
    }
};


// better approach O(n) and O(n)
// is question me hum apni string ko concatenate karenge
// then first and last char ko chhodkar concatenated str me apni original string ko dhundhenge
// if found then return true else false
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string concatenated = s + s;
        // in the inbuilt funciton we are passing the indexes from where to where to find the string s
        // so we are gonna find from 1 till n-2
        return concatenated.substr(1, concatenated.length() - 2).find(s) != string::npos;
    }
};

