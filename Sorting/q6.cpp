// https://leetcode.com/problems/sort-the-matrix-diagonally/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        for(int firstCol=0;firstCol<n;firstCol++)
        {
            vector<int> diagonal;
            int r=0,c=firstCol;
            while(r<m && c<n)
            {
                diagonal.push_back(mat[r][c]);
                r++,c++;
            }

            sort(diagonal.begin(),diagonal.end());

            r=0,c=firstCol;
            int i=0;
            while(r<m && c<n)
            {
                mat[r][c]=diagonal[i++];
                r++,c++;
            }
        }

        for(int firstRow=1;firstRow<m;firstRow++)
        {
            vector<int> diagonal;
            int c=0,r=firstRow;
            while(r<m && c<n)
            {
                diagonal.push_back(mat[r][c]);
                r++,c++;
            }

            sort(diagonal.begin(),diagonal.end());

            c=0,r=firstRow;
            int i=0;
            while(r<m && c<n)
            {
                mat[r][c]=diagonal[i++];
                r++,c++;
            }
        }

        return mat;
    }
};
