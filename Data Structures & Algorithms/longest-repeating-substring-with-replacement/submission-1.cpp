class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int j=0;
        int ans=INT_MIN;
        int maxFreq=0;
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
            maxFreq=max(maxFreq,mpp[s[i]]);
            if(i - j + 1 - maxFreq > k)
            {
                mpp[s[j]]--;
                j++;
            }
            ans=max(ans,i - j + 1);
        }
        return ans;
    }
};
