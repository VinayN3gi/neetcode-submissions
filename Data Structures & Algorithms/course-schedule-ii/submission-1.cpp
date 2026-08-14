class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<int> seen(numCourses,0);
        int count=0;
        for(int i=0;i<pre.size();i++)
        {
            int a=pre[i][0];
            int b=pre[i][1];
            adj[b].push_back(a);
            seen[a]++;
        }
        queue<int> q;
        for(int i=0;i<seen.size();i++)
        {
            if(seen[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int x=q.front();q.pop();
            count++;
            ans.push_back(x);
            for(int i:adj[x])
            {
                seen[i]--;
                if(seen[i]==0) q.push(i);
            }
        }

        if(count==numCourses) return ans;
        return {};
    }
};
