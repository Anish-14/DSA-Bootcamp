// https://leetcode.com/problems/unique-3-digit-even-numbers/description/


class Solution {
public:
    void helper(vector<int>& digits, vector<bool>& used, int depth, int current, unordered_set<int>& s){
        if(depth==3){
            if(current%2==0){
                s.insert(current);
            }
            return;
        }
        for(int i=0;i<digits.size();i++){
            if(!used[i]){
                if(depth==0 && digits[i]==0){
                    continue;
                }
                used[i]=true;
                int newNumber = current*10+digits[i]; //forming a number
                helper(digits,used,depth+1,newNumber,s);
                used[i]=false;
            }
        }
    }
    int totalNumbers(vector<int>& digits) {
        vector<bool> used(digits.size(),false);
        unordered_set<int> s;
        helper(digits,used,0,0,s);
        return s.size();
    }
};
