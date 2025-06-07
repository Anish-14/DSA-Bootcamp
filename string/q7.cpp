// https://leetcode.com/problems/repeated-substring-pattern/description/?envType=problem-list-v2&envId=string
// repeated substring pattern

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
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string concatenated = s + s;
        return concatenated.substr(1, concatenated.length() - 2).find(s) != string::npos;
    }
};

