// https://leetcode.com/problems/stamping-the-sequence/description/

class Solution {
    int n,m;
private:
    int getIndex(string &stamp, string &target){
        for(int i = 0; i<= m-n; i++){
            bool flag = false;
            int s = 0, t = i;
            while(s < n && t < m && (target[t] == '?' || target[t] == stamp[s])){
                if(target[t] != '?')    flag = true;
                s++, t++;
            }
            if(s == n && flag)  return i;
        }

        return -1;
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        n = stamp.size(), m = target.size();
        string temp = "";
        for(int i = 0; i<m; i++)    temp += '?';

        vector<int> ans;

        while(temp != target){
            int index = getIndex(stamp, target);
            if(index == -1) return {};

            ans.push_back(index);
            for(int i = index; i < index + n; i++){
                target[i] = '?';
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
