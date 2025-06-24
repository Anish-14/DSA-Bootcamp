// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// my solution 
class Solution {
public:
    void remove(unordered_map<char, int> &m, int st, int e, string &s){
        for(int i = st; i<= e; i++){
            m.erase(s[i]);
        }
    }
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        unordered_map<char, int> m;
        int st = 0;
        int e = 0;
        int ans = 1;

        for(int i = 0; i<s.length(); i++){
            char ch = s[i];
            if(m.find(ch) != m.end()){
                // ans save
                if(e - st + 1 > ans){
                    ans = e-st+1;
                }
                int index = m[s[i]];
                remove(m,st,index,s);
                st = index + 1;
            }
            else{
                e = i;
            }
            m[s[i]] = i;
        }
        // again check karo ho skta hai all elements in the string are unique so you need to check at last also for the size
        if(e - st + 1 > ans){
            ans = e-st+1;
        }
        return ans;
    }
};



// best solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int n = s.size();
        int hash[256];
        for(int i = 0; i < 256; i++) hash[i] = -1;
        int max_size = 0;
        
        while(r < n) {
            if(hash[s[r]] == -1 || hash[s[r]] < l) {
                hash[s[r]] = r;
                max_size = max(max_size, r - l + 1);
                r++;
            }
            else {
                l = hash[s[r]] + 1;
                hash[s[r]] = r;  // update new position
                r++;
            }
        }
        return max_size;
    }
};
