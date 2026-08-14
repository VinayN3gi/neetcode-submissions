class Solution {
public:
    void solve(vector<string> &ans,string &digits,
    int curr,string temp,unordered_map<char,vector<char>> &mpp)
    {
        if(temp.size()==digits.size())
        {
            ans.push_back(temp);
        }
        for(char x:mpp[digits[curr]])
        {
            temp.push_back(x);
            solve(ans,digits,curr+1,temp,mpp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        unordered_map<char,vector<char>> mpp={
            {'2',{'a','b','c'}},
            {'3',{'d','e','f'}},
            {'4',{'g','h','i'}},
            {'5',{'j','k','l'}},
            {'6',{'m','n','o'}},
            {'7',{'p','q','r','s'}},
            {'8',{'t','u','v'}},
            {'9',{'w','x','y','z'}}
        };
        vector<string> ans;
        string temp="";
        solve(ans,digits,0,temp,mpp);
        return ans;    

    }
};
