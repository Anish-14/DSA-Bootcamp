// https://leetcode.com/problems/orderly-queue/description/


class Solution {
public:
    string orderlyQueue(string s, int k) {
        // if K is larger than 1 then It can be sorted properly
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        // ek ek word ko peeche kar ke smallest lexographical order wala select kar rhe hai
        string res = s;
        for(int i = 1; i<s.length(); i++){
            res = min(res, s.substr(i) + s.substr(0,i));
        }
        return res;
    }
};
