class Solution {
public:
    vector<int> r1={-1,1,0,0};
    vector<int> r2={0,0,-1,1};
    void dfs(vector<vector<char>> &grid,vector<vector<int>> &seen,
    int row,int col)
    {
        for(int i=0;i<4;i++)
        {
            int newr=row + r1[i];
            int newc=col + r2[i];
            if(newr<0 || newr>=grid.size() || newc<0 || newc>=grid[0].size() || seen[newr][newc] || grid[newr][newc]=='0') continue;
            seen[newr][newc]=1;
            dfs(grid,seen,newr,newc);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> seen(grid.size(),vector<int>(grid[0].size(),0));
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!seen[i][j] && grid[i][j]=='1')
                {
                    seen[i][j]=1;
                    dfs(grid,seen,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
