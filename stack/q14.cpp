// https://leetcode.com/problems/maximal-rectangle/description/


// this uses the same concept as the previous question, for the area fun.
// we just have to make the presum matrix and we are good to go
class Solution {
public:
int area(vector<int>& heights) {
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi=0;
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<m;i++)
        {
            int presum=0;
            for(int j=0;j<n;j++)
            {
                if(matrix[j][i]=='0')
                {
                    presum=0;
                    ans[j][i]=0;
                }
                else
                {
                    presum += (matrix[j][i] - '0');
                    ans[j][i]=presum;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,area(ans[i]));
        }
        return maxi;
    }
};





// solution without stack, the above solution has better TC and this solution has better SC
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols + 1, 0); // Include an extra element for easier calculation
        int maxArea = 0;
        
        for (const auto& row : matrix) {
            for (int i = 0; i < cols; i++) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }
            
            // Calculate max area using histogram method
            int n = heights.size(); // Number of bars in the histogram
            
            for (int i = 0; i < n; i++) {
                for (int j = i, minHeight = INT_MAX; j < n; j++) {
                    minHeight = min(minHeight, heights[j]);
                    int area = minHeight * (j - i + 1);
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};
