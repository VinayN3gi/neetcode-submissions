class Solution {
public: 
    int isPalindrome(string s,int start,int end)
    {
        int count=0;
        while(start>=0 && end<s.size() && s[start]==s[end])
        {
            start--;
            end++;
            count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            int val1=isPalindrome(s,i,i);
            ans=ans + val1;
            int val2=isPalindrome(s,i,i+1);
            ans=ans + val2;
        }
        return ans;
    }
};
