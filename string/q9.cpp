// https://leetcode.com/problems/longest-palindromic-substring/description/


class Solution {
public:
    string longestPalindrome(string s) {
        int l=s.size();
        int left=0,right=0;
        int str=0,res=0;
        // we are going at each element and assuming it to be the middle element of the pallindrome
        for(int i=0;i<l;i++)
        {
            // middle element i hai
            right=i;
            // jab tak same hai tab tak move karte raho
            while(s[i]==s[right])
            {
                right++;
            }
            // now right is at right of the middle pallindrome

            // initialize left left of the middle element
            left=i-1;
            // now compare both right and left
            while(left>=0&&right<l&&s[left]==s[right])
            {
                left--;
                right++;
            }
            // save your answer if found a bigger pallindrome
            left=left+1;
            if(right-left>res)
            {
                res=right-left;
                str=left;
            }
        }
        return s.substr(str,res);
    }
};
