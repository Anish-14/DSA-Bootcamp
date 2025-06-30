// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vis(26,-1);
        for(int i = 0; i<s.length(); i++){
            int index = s[i] - 'a';
            if(vis[index] == -1){
                vis[index] = i;
            }
            else{
                vis[index] = -2;
            }
        }

        int idx = -1;
        for(int i = 0; i<26; i++){
            if(vis[i] >= 0 && (idx == -1 || vis[i] < vis[idx])){
                idx = i;
            }
        }

        if(idx == -1){
            return -1;
        }
        return vis[idx];
    }
};
