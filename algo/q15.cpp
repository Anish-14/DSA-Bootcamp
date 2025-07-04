// https://leetcode.com/problems/wildcard-matching/description/

// very good problem, do solve it

//Recursion
class Solution {
public:
    bool recur(int i, int j, string& s, string& p){
        if(i<0 && j<0)return true;
        if(j<0) return false;
        if(i<0){
            while(j>=0 && p[j] == '*') j--;
            if(j<0) return true;
            return false;
        }

        if(p[j] == '?' || s[i] == p[j]){
            return recur(i-1, j-1, s, p);
        }
        else if(p[j] == '*'){
            bool take = recur(i-1, j, s, p);
            bool not_take = recur(i, j-1, s, p);

            return take || not_take;
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();

        return recur(n1-1, n2-1, s, p);
    }
};

//Memoization
class Solution {
public:
    bool recur(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i<0 && j<0)return true;
        if(j<0) return false;
        if(i<0){
            while(j>=0 && p[j] == '*') j--;
            if(j<0) return true;
            return false;
        }
        if(dp[i][j]!= -1) return dp[i][j];

        if(p[j] == '?' || s[i] == p[j]){
            dp[i][j]= recur(i-1, j-1, s, p, dp);
        }
        else if(p[j] == '*'){
            bool take = recur(i-1, j, s, p, dp);
            bool not_take = recur(i, j-1, s, p, dp);

            dp[i][j] = take || not_take;
        }
        else dp[i][j] = false;
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();

        vector<vector<int>>dp(n1, vector<int>(n2, -1));
        return recur(n1-1, n2-1, s, p, dp);
    }
};

//Tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();

        vector<vector<bool>>dp(n1+1, vector<bool>(n2+1, false));
        dp[0][0] = true;
        for(int i=1; i<=n2; i++){
            if(p[i-1] == '*') dp[0][i] = true;
            else break;
        }

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(p[j-1] == '?' || s[i-1] == p[j-1]){
                    dp[i][j]= dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    bool take = dp[i-1][j];
                    bool not_take = dp[i][j-1];

                    dp[i][j] = take || not_take;
                }
                else dp[i][j] = false;
            }
        }
        return dp[n1][n2];
    }
};

//Space Optimisation
class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();

        //vector<vector<bool>>dp(n1+1, vector<bool>(n2+1, false));
        vector<bool>dp(n2+1, false);
        dp[0] = true;
        for(int i=1; i<=n2; i++){
            if(p[i-1] == '*') dp[i] = true;
            else break;
        }

        for(int i=1; i<=n1; i++){
            vector<bool>curr(n2+1, false);
            for(int j=1; j<=n2; j++){
                if(p[j-1] == '?' || s[i-1] == p[j-1]){
                    curr[j]= dp[j-1];
                }
                else if(p[j-1] == '*'){
                    bool take = dp[j];
                    bool not_take = curr[j-1];

                    curr[j] = take || not_take;
                }
                else curr[j] = false;
            }
            dp = curr;
        }
        return dp[n2];
    }
};
