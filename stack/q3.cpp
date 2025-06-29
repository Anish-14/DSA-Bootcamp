// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/


// string solution
class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0, n = s.length();
        for (int j = 0; j < n; ++j, ++i) {
            s[i] = s[j];
            if (i > 0 && s[i - 1] == s[i]) // count = 2
                i -= 2;
        }
        return s.substr(0, i);
    }
};



// this is the stack solution , here the string we are using as stack only
string removeDuplicates(string S) {
    string res = "";
    for (char& c : S)
        if (res.size() && c == res.back())
            res.pop_back();
        else
            res.push_back(c);
    return res;
}
