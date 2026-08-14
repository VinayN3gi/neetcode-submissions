class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> temp(m,vector<int>(n,1));
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                temp[i][j]=temp[i-1][j] + temp[i][j-1];
            }
        }

        return temp[m-1][n-1];
    }
};
