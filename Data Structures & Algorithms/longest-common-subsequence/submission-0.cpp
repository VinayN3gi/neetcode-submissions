class Solution {
public:
    int solve(string text1,string text2,int i ,int j,vector<vector<int>> &seen)
    {
        if(i >=text1.size() || j>=text2.size()) return 0;
        if(seen[i][j]!=-1) return seen[i][j];
        int ans=0;
        if(text1[i]==text2[j])
        {
            int val=1 + solve(text1,text2,i+1,j+1,seen);
            seen[i][j]=val;
            return val;
        }

        int val=max(solve(text1,text2,i+1,j,seen) , solve(text1,text2,i,j+1,seen));
        seen[i][j]=val;
        return seen[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> seen(text1.size(),vector<int>(text2.size(),-1));
        return solve(text1,text2,0,0,seen);
    }
};
