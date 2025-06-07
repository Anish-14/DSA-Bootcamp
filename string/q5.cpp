// https://leetcode.com/problems/isomorphic-strings/description/?envType=problem-list-v2&envId=string
// isomorphic strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> charIndexS;
        unordered_map<char, int> charIndexT;

        for (int i = 0; i < s.length(); i++) {
            if (charIndexS.find(s[i]) == charIndexS.end()) {
                charIndexS[s[i]] = i;
            }

            if (charIndexT.find(t[i]) == charIndexT.end()) {
                charIndexT[t[i]] = i;
            }

            if (charIndexS[s[i]] != charIndexT[t[i]]) {
                return false;
            }
        }

        return true;   
    }
};

// the following solution uses the same concept just the space complexity is constant

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //optimal solution, TS = O(N), SC = 0(1)
        //declare the hash maps
        int s_map[128] = {0};
        int t_map[128] = {0};

        for(int i = 0; i<s.size(); i++){
            if(s_map[s[i]] != t_map[t[i]])
            return false;

            //assign values with i +=1;
            s_map[s[i]] = i+1;
            t_map[t[i]] = i+1;
        }
    return true;
    }
};
