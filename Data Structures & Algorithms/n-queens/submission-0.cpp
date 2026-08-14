class Solution {
public:
    void solve(vector<vector<string>> &ans,vector<string> temp,int n,
    int curr,unordered_set<int> &col,unordered_set<int> &d1,unordered_set<int> &d2)
    {
        if(curr==n)
        {
            ans.push_back(temp);
            return ;
        }

        for(int i=0;i<n;i++)
        {
            if(col.count(i) || d1.count(i - curr) || d2.count(i + curr)) continue;
            else
            {
                col.insert(i);
                d1.insert(i - curr);
                d2.insert(i + curr);
                temp[curr][i]='Q';
                solve(ans,temp,n,curr+1,col,d1,d2);
                temp[curr][i]='.';
                col.erase(i);
                d1.erase(i-curr);
                d2.erase(i+curr);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string str="";
        for(int i=0;i<n;i++) str=str + ".";
        vector<string> temp;
        for(int i=0;i<n;i++) temp.push_back(str);
        vector<vector<string>> ans;
        unordered_set<int> col;
        unordered_set<int> d1;
        unordered_set<int> d2;
        solve(ans,temp,n,0,col,d1,d2);
        return ans;
    }
};
