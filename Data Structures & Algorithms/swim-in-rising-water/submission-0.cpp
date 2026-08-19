class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();

            int r = pos.first;
            int c = pos.second;

            if (r == n - 1 && c == n - 1)
                return time;

            if (time > dist[r][c])
                continue;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                int newTime = max(time, grid[nr][nc]);

                if (newTime < dist[nr][nc]) {
                    dist[nr][nc] = newTime;
                    pq.push({newTime, {nr, nc}});
                }
            }
        }

        return -1;
    }
};