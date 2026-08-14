class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        int i=0;
        while(i<s.size())
        {
            if(isalnum(s[i])) ans=ans + (char)tolower(s[i]);
            i++;
        }
        i=0;
        int j=ans.size() - 1 ;
        while(i<j)
        {
            if(ans[i]!=ans[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};
