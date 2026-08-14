class Solution {
public:
    bool isPalindrome(string &s, int l, int r)
     {
        while (l < r)
        {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }
        return true;
    }
    void solve(vector<vector<string>> &ans,vector<string> temp,int curr,string s)
    {
        if(curr==s.size())
        {
            ans.push_back(temp);
            return ;
        }
        for(int i=curr;i<s.size();i++)
        {
            //string val=s.substr(curr,i-curr+1);
            if(isPalindrome(s,curr,i))
            {
                temp.push_back(s.substr(curr,i-curr+1));
                solve(ans,temp,i+1,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(ans,temp,0,s);
        return ans;
    }
};
