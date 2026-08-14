class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set seen(wordList.begin(),wordList.end());
        if(!seen.count(endWord)) return false;
        queue<string> q;
        q.push(beginWord);
        int count=1;
        int formed=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                string temp=q.front();q.pop();
                if(temp==endWord)
                {
                    formed=1;
                    return count;
                }
                for(int i=0;i<temp.size();i++)
                {
                    char x=temp[i];
                    for(int k='a';k<='z';k++)
                    {
                        if(k==x) continue;
                        else
                        {
                            temp[i]=k;
                            if(seen.count(temp))
                            {
                                q.push(temp);
                                seen.erase(temp);
                            }
                        }
                        temp[i]=x;
                    }
                }
            }
            count++;
        }
        if(formed) return count;
        else return 0;
    }
};
