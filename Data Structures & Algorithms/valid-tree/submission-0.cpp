class UnionSet
{
    public:
        vector<int> parent;
        vector<int> size;
        UnionSet(int n)
        {
            parent.resize(n);
            for(int i=0;i<n;i++) parent[i]=i;
            size.resize(n);
            for(int i=0;i<n;i++) size[i]=1;
        }

        int findParent(int x)
        {
            if(parent[x]==x) return x;
            return parent[x]=findParent(parent[x]);
        }

        void join(int a , int b)
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
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionSet u(n);
        if(edges.size()!=n-1) return false;
        for(int i=0;i<edges.size();i++)
        {
            if(u.findParent(edges[i][0])==u.findParent(edges[i][1])) return false;
            u.join(edges[i][0],edges[i][1]);
        }
        return true;
    }
};
