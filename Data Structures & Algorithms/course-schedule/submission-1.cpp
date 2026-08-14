class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> seen(numCourses,0);
        vector<vector<int>> adj(numCourses);        
        
        for(int i=0;i<pre.size();i++)
        {
            int a=pre[i][0];
            int b=pre[i][1];
            seen[a]++;
            adj[b].push_back(a);
        }

        queue<int> q;
        int count=0;
        for(int i=0;i<seen.size();i++) {
            if(seen[i]==0){
                q.push(i);
        }}

        while(!q.empty())
        {
            auto x=q.front();q.pop();
            count++;
            for(int t:adj[x])
            {
                seen[t]--;
                if(seen[t]==0) q.push(t);
            }
        }

        cout<<count<<endl;
        return count==numCourses;

    }
};
