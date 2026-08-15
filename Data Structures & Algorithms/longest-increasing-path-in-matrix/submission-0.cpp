class Solution {
public:
    vector<int> row1={-1,1,0,0};
    vector<int> row2={0,0,-1,1};
    int solve(vector<vector<int>> &matrix,int i ,int j,vector<vector<int>> &seen)
    {
        int ans=1;
        if(seen[i][j]!=-1) return seen[i][j];
        for(int k=0;k<4;k++)
        {
            int newr=i + row1[k];
            int newc=j + row2[k];
            if(newr<0 || newr>=matrix.size() || newc<0 || 
            newc>=matrix[0].size() || matrix[newr][newc]<=matrix[i][j]) continue;
            else
            {
                ans=max(ans,1 + solve(matrix,newr,newc,seen));
            }
        }
        seen[i][j]=ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        vector<vector<int>> seen(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                ans=max(ans,solve(matrix,i,j,seen));
            }
        }
        return ans;
    }
};
