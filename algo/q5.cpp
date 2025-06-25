// https://leetcode.com/problems/reverse-string/description/

class Solution {
public:
    void swap(vector<char> &s, int ind1, int ind2){
        char val = s[ind1];
        s[ind1] = s[ind2];
        s[ind2] = val;
    }
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size()-1;

        while(i<=j){
            swap(s,i,j);
            i++;
            j--;
        }

        return ;
    }
};
