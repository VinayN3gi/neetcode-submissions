class Solution {
public:
    void solve(vector<string> &ans,int left,int right,int n,string temp)
    {
        if(left + right == 2* n)
        {
            ans.push_back(temp);
            return ;
        }
        if(left < n)
        {
            temp.push_back('(');
            solve(ans,left+1,right,n,temp);
            temp.pop_back();
        }
        if(right < n && right < left)
        {
            temp.push_back(')');
            solve(ans,left,right + 1 , n , temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        vector<string> ans;
        solve(ans,0,0,n,temp);
        return ans;
    }
};
