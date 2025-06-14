// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    void solve(vector<string> &ans, int n, string str, int open, int close){
        if(open > n || close > n){
            return ;
        }
        if(str.length() == 2*n){
            ans.push_back(str);
            return ;
        }
        
        if(close < n)
            solve(ans, n, str + '(', open + 1, close);
        
        if(open > close)
            solve(ans, n, str + ')', open, close + 1);        

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans,n,"",0,0);

        return ans;
    }
};
