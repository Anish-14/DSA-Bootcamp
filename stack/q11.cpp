// https://leetcode.com/problems/decode-string/description/


class Solution {
public:
    string decodeString(string s) {
        stack<int> numstack;
        stack<char> charstack;
        string temp="";
        string res="";
        for(int i=0;i<s.length();i++){
            int cnt=0;
            if(s[i]>='0' && s[i]<='9'){
                while(s[i]>='0' && s[i]<='9'){
                    cnt=cnt*10+s[i]-'0';
                    i++;
                }
                i--;
                numstack.push(cnt);
            }
            else if(s[i]==']'){
                temp="";
                cnt=numstack.top();
                numstack.pop();
                while(charstack.top()!='['){
                    temp=charstack.top()+temp;
                    charstack.pop();
                }
                charstack.pop();
                for(int j=0;j<cnt;j++){
                    res=res.append(temp);
                }
                for(int j=0;j<res.length();j++){
                    charstack.push(res[j]);
                }
                res="";
            }
            else{
                charstack.push(s[i]);
            }
        }
        while(!charstack.empty()){
            res=charstack.top()+res;
            charstack.pop();
        }
        return res;
    }
};



// this is better solution than the above, but the two stack approach is also quite good
class Solution {
public:
    string decodeString(string s) {
       int n = s.size();
       string ans = "";
       for(int i=0;i<n;i++){
        if(isdigit(s[i])){
            int num = 0;
            while(s[i]!='['){
                int x = s[i]-'0';
                num*=10;
                num+=x;
                i++;
            }
            string pass = "";
            i++;
            int count = 1;
            while(count!=0){
                if(s[i]=='['){
                    count++; 
                } else if(s[i]==']'){
                    count--;
                }
                if(count==0){
                    break;
                }
                pass+=s[i];
                i++;
            }
            string temp = decodeString(pass);
            for(int j=0;j<num;j++){
                ans+=temp;
            }
        } else {
            ans+=s[i];
        }
       }
       return ans; 
    }
};
