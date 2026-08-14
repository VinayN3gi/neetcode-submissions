class UnionSet
{
    public:
        vector<int> size;
        vector<int> parent;
        UnionSet(int n)
        {
            size.resize(n+1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++) parent[i]=i;
            for(int i=0;i<=n;i++) size[i]=1;
        }

        int findParent(int x)
        {
            if(parent[x]==x) return x;
            else return findParent(parent[x]);
        }

        void join(int a,int b)
        {
            int pa=findParent(a);
            int pb=findParent(b);

            if(pa==pb) return ;

            if(size[pa] >=size[pb])
            {
                size[pa]=size[pa] + size[pb];
                parent[pb]=pa;
            }
            else
            {
                size[pb]=size[pb] + size[pa];
                parent[pa]=pb;
            }
        }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        UnionSet u(edges.size());
        for(int i=0;i<edges.size();i++)
        {
            int pa=u.findParent(edges[i][0]);
            int pb=u.findParent(edges[i][1]);
            if(pa==pb)
            {
                ans.push_back({edges[i][0],edges[i][1]});
            }
            else
            {
                u.join(edges[i][0],edges[i][1]);
            }
        }

        return ans[ans.size() - 1];
    }
};
