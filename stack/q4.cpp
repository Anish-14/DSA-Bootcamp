// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/


class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int b = 0;

        for(char ch : s){
            if(ch == '('){
                b++;
                maxi = max(maxi, b);
            }
            else if(ch == ')'){
                b--;
            }
        }

        return maxi;
    } 
};
