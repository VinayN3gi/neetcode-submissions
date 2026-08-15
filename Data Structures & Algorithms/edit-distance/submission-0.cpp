class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> seen(word1.size() + 1 , vector<int>(word2.size() + 1 , 0));
        for(int i=0;i<=word2.size();i++)
        {
            seen[0][i]=i;
        }
        for(int i=0;i<=word1.size();i++)
        {
            seen[i][0]=i;
        }

        for(int i=1;i<=word1.size();i++)
        {
            for(int j=1;j<=word2.size();j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    seen[i][j]=seen[i-1][j-1];
                }
                else
                {
                    seen[i][j]=1 + min({seen[i-1][j],seen[i][j-1],seen[i-1][j-1]});
                }
            }
        }   

        return seen[word1.size()][word2.size()];

    }
};
