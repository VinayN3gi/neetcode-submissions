class Solution {
public:
    vector<int> r1={-1,1,0,0};
    vector<int> r2={0,0,-1,1};
    int solve(vector<vector<int>> &grid,vector<vector<int>> &seen,int row,int col)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || seen[row][col] ||         grid[row][col]==0) return 0;
        int ans=1;
        seen[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int newr=r1[i] + row;
            int newc=r2[i] + col;
            ans=ans + solve(grid,seen,newr,newc);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> seen(grid.size(),vector<int>(grid[0].size(),0));
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!seen[i][j] && grid[i][j]==1)
                {
                    int temp=solve(grid,seen,i,j);
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};
