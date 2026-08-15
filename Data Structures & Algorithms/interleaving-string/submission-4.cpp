class Solution {
public:
    bool solve(string &s1, string &s2, string &s3,
               int i, int j, vector<vector<int>> &seen) {

        int k = i + j;

        // We successfully consumed all of s3
        if(k == s3.size())
            return true;

        if(seen[i][j] != -1)
            return seen[i][j];

        bool ans = false;

        // Take character from s1
        if(i < s1.size() && s1[i] == s3[k]) {
            ans = ans || solve(s1, s2, s3, i + 1, j, seen);
        }

        // Take character from s2
        if(j < s2.size() && s2[j] == s3[k]) {
            ans = ans || solve(s1, s2, s3, i, j + 1, seen);
        }

        seen[i][j] = ans;

        return ans;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if(s1.size() + s2.size() != s3.size())
            return false;

        vector<vector<int>> seen(
            s1.size() + 1,
            vector<int>(s2.size() + 1, -1)
        );

        return solve(s1, s2, s3, 0, 0, seen);
    }
};