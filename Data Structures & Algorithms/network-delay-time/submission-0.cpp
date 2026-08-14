class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for(int i = 0; i < times.size(); i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({v, wt});
        }

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, k}); // {distance, node}

        while(!pq.empty())
        {
            auto x = pq.top();
            pq.pop();

            int val  = x.first;   // current distance
            int node = x.second;  // current node

            for(auto &[nei, wt] : adj[node])
            {
                if(val + wt < dist[nei])
                {
                    dist[nei] = val + wt;

                    // push TOTAL distance
                    pq.push({dist[nei], nei});
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};