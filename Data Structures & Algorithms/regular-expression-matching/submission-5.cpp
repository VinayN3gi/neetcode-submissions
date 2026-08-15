class Solution {
public:
    bool solve(string s,string p,int i,int j,vector<vector<int>> &seen)
    {
        if(j==p.size())
        {
            return i==s.size();
        }
        if(i<s.size() && j < p.size() && seen[i][j]!=-1) return seen[i][j];
        bool ans=false;
        if(j+1 < p.size() && p[j+1]=='*')
        {
            ans=ans || solve(s,p,i,j+2,seen);
            if(i<s.size() && (s[i]==p[j] || p[j]=='.'))
            {
                ans=ans || solve(s,p,i+1,j,seen);
            }
        }
        else if(i<s.size() && (s[i]==p[j] || p[j]=='.'))
        {
            ans=ans | solve(s,p,i+1,j+1,seen);
        }
        seen[i][j]=ans;
        return ans;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> seen(s.size() + 1 , vector<int>(p.size() + 1 , -1));
        return solve(s,p,0,0,seen);
    }
};
