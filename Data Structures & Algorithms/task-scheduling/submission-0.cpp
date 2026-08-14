class Compare
{
    public:
        bool operator()(int a,int b)
        {
            return a < b;
        }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mpp;
        for(int i=0;i<tasks.size();i++) mpp[tasks[i]]++;
        priority_queue<int,vector<int>,Compare> pq;
        for(auto &[val,freq] : mpp) pq.push(freq);
        queue<pair<int,int>> q; // freq , available
        int time=0;
        while(!q.empty() || !pq.empty())
        {
            time++;
            while(!q.empty() && time >= q.front().second)
            {
                auto x=q.front();q.pop();
                pq.push(x.first);
            }
            if(!pq.empty())
            {
                int x=pq.top();pq.pop();
                if(x-1!=0)
                {
                    q.push({x-1,time + n + 1});
                }
                else continue;
            }
            else continue;
        }

        return time;
    }
};
