class Solution {
public:
    int solve(int n)
    {
        int ans=0;
        while(n > 0)
        {
            if(n & 1) ans++;
            n=n >> 1;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {

            int x=solve(i);
            ans.push_back(x);
        }
        return ans;
    }
};
