class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int j=0;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
            while(mpp[s[i]] > 1)
            {
                if(mpp[s[j]]==1) mpp.erase(s[j]);
                else mpp[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};
