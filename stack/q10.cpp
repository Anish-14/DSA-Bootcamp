// https://leetcode.com/problems/remove-duplicate-letters/description/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> lastOccurrence;
        for (int i = 0; i < s.length(); i++) {
            lastOccurrence[s[i]] = i;
        }

        stack<char> stack;
        vector<bool> visited(26);

        for (int i = 0; i < s.length(); i++) {
            if (visited[s[i] - 'a']) {
                continue;
            }

            while (!stack.empty() && s[i] < stack.top() && i < lastOccurrence[stack.top()]) {
                visited[stack.top() - 'a'] = 0;
                stack.pop();
            }

            visited[s[i] - 'a'] = 1;
            stack.push(s[i]);
        }

        string result;
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;        
    }
};
