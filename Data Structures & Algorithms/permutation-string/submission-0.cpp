class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        unordered_map<char,int> mpp1;
        for(int i=0;i<s1.size();i++) mpp1[s1[i]]++;
        unordered_map<char,int> mpp2;
        for(int i=0;i<s1.size();i++) mpp2[s2[i]]++;
        int i=0;
        int j=s1.size();
        if(mpp1==mpp2) return true;
        while(j<s2.size())
        {
            mpp2[s2[j]]++;
            if(mpp2[s2[i]]==1) mpp2.erase(s2[i]);
            else mpp2[s2[i]]--;
            if(mpp1==mpp2) return true;
            j++;
            i++;
        }
        return false;
    }
};
