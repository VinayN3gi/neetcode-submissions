class Solution {
public:
    string palindrome(string s,int start,int end,int maxLen)
    {
        string ans="";
        while(start >=0 && end<s.size())
        {
            if(s[start]!=s[end]) return ans;
            if(end - start + 1 > maxLen)
            {
                ans=s.substr(start,end - start + 1);
            }
            start--;
            end++;
        }

        return ans;  
    }
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            string val1=palindrome(s,i,i+1,ans.size());
            string val2=palindrome(s,i,i,ans.size());
            if(val1.size() > ans.size()) ans=val1;
            if(val2.size() > ans.size()) ans=val2;
        }

        return ans;
    }
};
