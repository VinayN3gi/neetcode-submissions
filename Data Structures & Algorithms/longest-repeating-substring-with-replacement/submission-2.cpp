class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int maxFreq=0;
        int i=0;
        int ans=0;
        for(int j=0;j<s.size();j++)
        {
            mpp[s[j]]++;
            maxFreq=max(maxFreq,mpp[s[j]]);
            while( (j - i + 1) - maxFreq > k)
            {
                if(mpp[s[i]]==1) mpp.erase(s[i]);
                else mpp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
