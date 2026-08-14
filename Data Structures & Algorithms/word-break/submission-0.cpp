class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> seen(s.size() + 1 , false);
        seen[0]=true;
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        for(int i=0;i<s.size();i++)
        {
            for(int j=i+1;j<=s.size(); j++)
            {
                if(words.count(s.substr(i,j-i)) && seen[i])
                {
                    seen[j]=true;
                }
            }
        }

        return seen[s.size()];
    }
};
