class Compare
{
    public:
        bool operator()(vector<int> a,vector<int> b)
        {
            int x1=a[0] - 0;
            int x2=a[1] - 0;
            double val1=sqrt((x1 * x1) + (x2 * x2));
            int y1=b[0] - 0;
            int y2=b[1] - 0;
            double val2=sqrt((y1 * y1) + (y2 * y2));
            return val1 < val2;
        }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,Compare> pq;
        
        for(int i=0;i<points.size();i++)
        {
            pq.push(points[i]);
            if(pq.size() > k) pq.pop();
        }
        
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
