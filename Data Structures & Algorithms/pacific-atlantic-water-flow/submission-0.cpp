class Solution {
public:
    vector<int> r1 = {0, 0, -1, 1};
    vector<int> r2 = {-1, 1, 0, 0};

    void solve(vector<vector<int>> &heights,
               vector<vector<int>> &seen,
               queue<pair<int,int>> &q)
    {
        while(!q.empty())
        {
            auto x = q.front();
            q.pop();

            int row = x.first;
            int col = x.second;

            for(int i = 0; i < 4; i++)
            {
                int newr = row + r1[i];
                int newc = col + r2[i];

                if(newr < 0 || newr >= heights.size() ||
                   newc < 0 || newc >= heights[0].size() ||
                   seen[newr][newc] ||
                   heights[newr][newc] < heights[row][col])
                    continue;

                seen[newr][newc] = 1;
                q.push({newr, newc});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;

        // Top and Bottom rows
        for(int j = 0; j < n; j++)
        {
            q1.push({0, j});
            pacific[0][j] = 1;

            q2.push({m - 1, j});
            atlantic[m - 1][j] = 1;
        }

        // Left and Right columns
        for(int i = 0; i < m; i++)
        {
            q1.push({i, 0});
            pacific[i][0] = 1;

            q2.push({i, n - 1});
            atlantic[i][n - 1] = 1;
        }

        solve(heights, pacific, q1);
        solve(heights, atlantic, q2);

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};