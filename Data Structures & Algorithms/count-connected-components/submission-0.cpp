class UnionSet
{
    public:
        vector<int> parent;
        vector<int> size;
        
        UnionSet(int n)
        {
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++) parent[i]=i;
            for(int i=0;i<n;i++) size[i]=1;
        }
        int findParent(int x)
        {
            if(parent[x]==x) return x;
            else return parent[x]=findParent(parent[x]);
        }

        void join(int a,int b)
        {
            int pa=findParent(a);
            int pb=findParent(b);
            if(pb==pa) return ;
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
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionSet u(n);
        for(int i=0;i<edges.size();i++)
        {
            int pa=u.findParent(edges[i][0]);
            int pb=u.findParent(edges[i][1]);
            u.join(pa,pb);
        }

        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            int val=u.findParent(i);
            if(!mpp.count(val)) mpp[val]++;
            else mpp[val]++;
        }
        return mpp.size();
    }
};
