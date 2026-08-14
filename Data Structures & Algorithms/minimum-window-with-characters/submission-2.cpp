class Solution {
public:
    string minWindow(string s, string t) {

        if(s.size() < t.size()) return "";

        unordered_map<char,int> need;

        for(char c : t)
            need[c]++;

        int count = need.size();

        unordered_map<char,int> window;

        int i = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int j = 0; j < s.size(); j++)
        {
            window[s[j]]++;

            if(need.count(s[j]) && window[s[j]] == need[s[j]])
                count--;

            while(count == 0)
            {
                if(j - i + 1 < minLen)
                {
                    minLen = j - i + 1;
                    start = i;
                }

                window[s[i]]--;

                if(need.count(s[i]) && window[s[i]] < need[s[i]])
                    count++;

                i++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};