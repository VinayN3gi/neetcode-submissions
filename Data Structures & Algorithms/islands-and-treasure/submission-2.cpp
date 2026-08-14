class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0) q.push({i,j});
            }
        }
        int count=1;
        vector<int> r1={-1,1,0,0};
        vector<int> r2={0,0,-1,1};
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto x=q.front();q.pop();
                for(int i=0;i<4;i++)
                {
                    int newr=x.first + r1[i];
                    int newc=x.second + r2[i];
                    if(newr<0 || newr>=grid.size() || newc<0 || newc>=grid[0].size() || grid[newr][newc]==-1 || grid[newr][newc] <= count ) continue;
                    else
                    {
                        grid[newr][newc]=count;
                        q.push({newr,newc});
                    }
                }
            }
            count++;
        }
    }
};
