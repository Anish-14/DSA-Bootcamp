// https://leetcode.com/problems/minimum-window-substring/description/?envType=problem-list-v2&envId=string



class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()){
            return "";
        }       

        unordered_map<char, int> m;
        for(char i : t){
            m[i]++;
        }

        int startIndex = 0;
        vector<int> diff = {0, INT_MAX};
        int remainingChar = t.length();

        for(int endIndex = 0; endIndex < s.length(); endIndex++){
            char ch = s[endIndex];
            if(m.find(ch) != m.end() && m[ch] > 0){
                remainingChar--;
            }
            m[ch]--;


            if(remainingChar == 0){
                while(true){
                    char start = s[startIndex];
                    if(m.find(start) != m.end() && m[start] == 0){
                        break;
                    }
                    m[start]++;
                    startIndex++;
                }

                // answer save
                if(endIndex - startIndex < diff[1] - diff[0]){
                    diff[0] = startIndex;
                    diff[1] = endIndex;
                }

                // move forward
                // and jo matched char hai shuruaat wala usko ek se badha do
                m[s[startIndex]]++;
                startIndex++;
                remainingChar++;
            }
            
        }

        if(diff[1] >= s.length()){
            return "";
        }
        return s.substr(diff[0], diff[1] - diff[0] + 1);
    }
};
