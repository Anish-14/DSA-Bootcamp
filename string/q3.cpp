// https://leetcode.com/problems/roman-to-integer/description/?envType=problem-list-v2&envId=string
// roman to integer

// this is my solution where I've used map, but it is not required , below is a solution without it
class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();

        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int sum = 0;
        int prev = 0;
        for(int i = n-1; i>=0; i--){
            if(m[s[i]] >= prev){
                sum += m[s[i]];
            }
            else{
                sum = sum - m[s[i]];
            }
            prev = m[s[i]];
        }
        return sum;
    }
};


// solution without map
// in question it was given that there is not such thing like 'IC', so I don't need to consider that
// so we've to consider only possible configuration and for this given condition (which is actually how roman numbers are written)
// we don't need a map, we just need some checks

class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I') {
                if (s[i + 1] == 'V') {
                    total += 4;
                    i++;
                } else if (s[i + 1] == 'X') {
                    total += 9;
                    i++;
                } else {
                    total += 1;
                }
            } else if (s[i] == 'X') {
                if (s[i + 1] == 'L') {
                    total += 40;
                    i++;
                } else if (s[i + 1] == 'C') {
                    total += 90;
                    i++;
                } else {
                    total += 10;
                }
            } else if (s[i] == 'C') {
                if (s[i + 1] == 'D') {
                    total += 400;
                    i++;
                } else if (s[i + 1] == 'M') {
                    total += 900;
                    i++;
                } else {
                    total += 100;
                }
            } else if (s[i] == 'V') {
                total += 5;
            } else if (s[i] == 'L') {
                total += 50;
            } else if (s[i] == 'D') {
                total += 500;
            } else if (s[i] == 'M') {
                total += 1000;
            }
        }
        return total;
    }
};
