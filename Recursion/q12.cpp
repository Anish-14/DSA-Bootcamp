// https://leetcode.com/problems/palindrome-partitioning/description/

// all the medium questions were of same time
// all were focused on inclusion exclusion principle, which is important
class Solution {
public:
    int n;
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void solve(vector<vector<string>>&ans,vector<string>curr,string s,int idx){
        if(idx>=n){
            ans.push_back(curr);
            return;
        }

        for(int i=idx;i<n;i++){
            if(isPalindrome(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                solve(ans,curr,s,i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.length();

        vector<vector<string>>ans;
        vector<string>curr;

        solve(ans,curr,s,0);
        return ans;
    }
};
