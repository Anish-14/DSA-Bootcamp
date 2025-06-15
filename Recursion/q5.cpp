// https://leetcode.com/problems/string-to-integer-atoi/description/


// I've not used recursion here
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;      // index
        long long res = 0;
        bool limit = 0;
        bool neg = 0;
        int n = s.length();

        // remove the spaces
        while(i < n && s[i] == ' '){
            i++;
        }

        // check for the sign
        if(i < n && s[i] == '-'){
            neg = 1;
            i++;
        }
        else if(i < n && s[i] == '+'){
            i++;
        }

        // store the char
        while(i < n && s[i] >= '0' && s[i] <= '9'){
            res = res*10 + (s[i] - '0');
            if(res > INT_MAX){
                limit = true;
                break;
            }
            i++;
        }

        if(neg){
            if(limit){
                return INT_MIN;
            }
            return -res;
        }
        if(limit){
            return INT_MAX;
        }

        return res;
    }
};
