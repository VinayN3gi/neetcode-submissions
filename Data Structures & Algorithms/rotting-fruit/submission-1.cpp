class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int req=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) req++;
            }
        }
        vector<int> r1={-1,1,0,0};
        vector<int> r2={0,0,-1,1};
        if(req==0) return 0;
        int count=0;
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            count++;
            for(int i=0;i<size;i++)
            {
                auto x=q.front();q.pop();
                for(int i=0;i<4;i++)
                {
                    int newr=x.first + r1[i];
                    int newc=x.second + r2[i];
                    if(newr<0 || newr>=grid.size() || newc<0 || newc>=grid[0].size() || grid[newr][newc]==2 || grid[newr][newc]==0) continue;
                    else 
                    {
                        ans++;
                        grid[newr][newc]=2;
                        if(ans==req) return count;
                        q.push({newr,newc});
                    }
                }
            }
        }
        if(ans==req) return count;
        else return -1;
    }
};
