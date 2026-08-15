class Solution {
public:
    int solve(string s , string t , int i ,int j,vector<vector<int>> &seen)
    {
        if(j==t.size()) return 1;
        if(i>s.size()) return 0;
        if(i< s.size() && j<t.size() && seen[i][j]!=-1) return seen[i][j];
        int ans=0;
        if(i< s.size() && j<t.size() && s[i]==t[j])
        {
            ans=ans + solve(s,t,i+1,j+1,seen);
        }
        ans=ans + solve(s,t,i+1,j,seen);
        seen[i][j]=ans;
        return ans;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> seen(s.size() + 1,vector<int>(t.size() + 1,-1));
        return solve(s,t,0,0,seen);
    }
};
