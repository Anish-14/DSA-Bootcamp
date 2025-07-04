// https://leetcode.com/problems/largest-rectangle-in-histogram/description/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxi=0;
        int i=1;
        st.push(0);
        while(i<heights.size())
        {
            while(!st.empty()&&heights[st.top()]>heights[i])
            {
                int ele=st.top();
                st.pop();
                int total=0;
                int pse=st.empty()?-1:st.top();
                total=heights[ele]*(i-pse-1);
                maxi=max(maxi,total);
            }
            st.push(i);
            i++;
        }
        while(!st.empty())
        {
            int k=st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top(); 
            int area=(heights[k]*(heights.size()-pse-1));
            maxi=max(maxi,area);
        }
        return maxi;
    }
};
