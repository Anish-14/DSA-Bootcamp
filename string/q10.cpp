// https://leetcode.com/problems/find-all-anagrams-in-a-string/?envType=problem-list-v2&envId=string


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) return {};

        vector<int> freq(26, 0), window(26, 0), result;

        for (char c : p) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < p.size(); i++) {
            window[s[i] - 'a']++;
        }

        if (window == freq) {
            result.push_back(0);
        }

        for (int i = p.size(); i < s.size(); i++) {
            window[s[i] - 'a']++;
            window[s[i - p.size()] - 'a']--;

            if (window == freq) {
                result.push_back(i - p.size() + 1);
            }
        }

        return result;
    }
};
