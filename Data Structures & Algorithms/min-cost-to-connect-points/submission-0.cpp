class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> visit(points.size(),false);
        pq.push({0,0});
        int connected=0;
        int ans=0;
        while(connected < points.size())
        {
            auto temp=pq.top();pq.pop();
            int cost=temp.first;
            int u=temp.second;
            if(visit[u]) continue;
            connected++;
            visit[u]=true;
            ans=ans + cost ; 
            for(int i=0;i<points.size();i++)
            {
                if(visit[i]) continue;
                else
                {
                    int v = abs(points[u][0] - points[i][0]) + abs(points[u][1] - points[i][1]);        
                    pq.push({v,i});
                }
            }
        }
        return ans;
    }
};
