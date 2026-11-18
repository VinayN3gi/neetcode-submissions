class Solution {
public:
    string longestPalindrome(string s) {
       int maxLen=0;
       int start=0;
       for(int i=0;i<s.size();i++)
       {
            int left=i;
            int right=i;
            while(left>=0 && right < s.size() && s[left]==s[right])
            {
                left--;
                right++;
            }
            if(right - left - 1  > maxLen)
            {
                start=left + 1;
                maxLen=right - left - 1;
            }
            left=i;
            right=i + 1;
            while(left>=0 && right < s.size() && s[left]==s[right])
            {
                left--;
                right++;
            }
            if(right - left - 1 > maxLen)
            {
                start=left + 1;
                maxLen=right - left - 1;
            }
       } 

       return s.substr(start , maxLen);
    }
};
