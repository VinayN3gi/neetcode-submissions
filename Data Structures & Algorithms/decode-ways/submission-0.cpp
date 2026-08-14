class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        vector<int> temp(s.size() + 1 ,0);
        temp[0]=1;
        temp[1] = (s[0] == '0' ? 0:1);
        for(int i=2;i<=s.size();i++)
        {
            int oneDigit=stoi(s.substr(i-1,1));
            if(oneDigit >=1 && oneDigit<=9) temp[i]=temp[i] + temp[i-1];
            int twoDigit=stoi(s.substr(i-2,2));
            if(twoDigit>=10 && twoDigit<=26) temp[i]=temp[i] + temp[i-2];
        }

        return temp[s.size()];
    }
};
